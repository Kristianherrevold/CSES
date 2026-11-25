"""Import the JSON produced by export_cses.js without overwriting local files."""
import ast
import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
TASKS = {task_id: (folder, name) for task_id, name, folder in
         json.loads((ROOT / 'tools/cses_tasks.json').read_text())}


def main():
    data = json.loads(Path(sys.argv[1]).read_text())
    if data.get('version') != 1:
        raise ValueError('Unsupported export version')
    planned = []
    seen = set()
    for submission in data['submissions']:
        task_id = submission['taskId']
        if task_id in seen:
            raise ValueError(f'Duplicate task: {task_id}')
        seen.add(task_id)
        folder, name = TASKS[task_id]
        if submission['sender'] != 'kaherrev' or submission['verdict'] != 'ACCEPTED':
            raise ValueError(f'Unexpected sender or verdict: {task_id}')
        language = submission['language']
        if language.startswith('Python'):
            extension = '.py'
            ast.parse(submission['code'])
        elif language.startswith('C++'):
            extension = '.cpp'
        elif language == 'C' or language.startswith('C ('):
            extension = '.c'
        else:
            raise ValueError(f'Unsupported language: {language}')
        target = ROOT / folder / (name + extension)
        if target.exists():
            raise FileExistsError(target)
        planned.append((target, submission['code']))
    for target, code in planned:
        target.parent.mkdir(parents=True, exist_ok=True)
        with target.open('x') as output:
            output.write(code)
        print(target.relative_to(ROOT))
    print(f'Imported {len(planned)} solutions.')
    for error in data.get('errors', []):
        print('Export error:', error)


if __name__ == '__main__':
    main()
