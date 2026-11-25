// Run in the developer console of an authenticated https://cses.fi tab.
// Reads submissions with GET requests and downloads a local JSON file.
(async () => {
  if (location.origin !== 'https://cses.fi') throw new Error('Run this on https://cses.fi');
  const tasks = [[1755, "PalindromeReorder", "IntroductoryProblems"], [2165, "TowerOfHanoi", "IntroductoryProblems"], [3419, "MexGridConstruction", "IntroductoryProblems"], [3217, "KnightMovesGrid", "IntroductoryProblems"], [3311, "GridColoringI", "IntroductoryProblems"], [2431, "DigitQueries", "IntroductoryProblems"], [1621, "distinct_numbers", "Searching_Sorting"], [1084, "apartments", "Searching_Sorting"], [1090, "ferris_wheel", "Searching_Sorting"], [1091, "concert_tickets", "Searching_Sorting"], [1619, "restaurant_customers", "Searching_Sorting"], [1629, "movie_festival", "Searching_Sorting"], [1640, "sum_of_two_values", "Searching_Sorting"], [1643, "maximum_subarray_sum", "Searching_Sorting"], [1074, "stick_lengths", "Searching_Sorting"], [2183, "missing_coin_sum", "Searching_Sorting"], [2216, "collecting_numbers", "Searching_Sorting"], [2217, "collecting_numbers_2", "Searching_Sorting"], [1141, "playlist", "Searching_Sorting"], [1163, "traffic_lights", "Searching_Sorting"], [3420, "distinct_values_subarrays", "Searching_Sorting"], [3421, "distinct_values_subsequences", "Searching_Sorting"], [2162, "josephus_problem_1", "Searching_Sorting"], [3112, "hidden_integer", "Interactive"]];
  const parser = new DOMParser();
  const read = async path => {
    const response = await fetch(path, {credentials: 'same-origin'});
    if (!response.ok) throw new Error(`HTTP ${response.status}: ${path}`);
    return parser.parseFromString(await response.text(), 'text/html');
  };
  const exported = {version: 1, submissions: [], errors: []};
  for (const [taskId] of tasks) {
    try {
      const page = await read(`/problemset/task/${taskId}/`);
      const urls = [...new Set([...page.querySelectorAll('a[href]')]
        .map(a => a.getAttribute('href'))
        .filter(href => /^\/problemset\/result\/\d+\/$/.test(href)))];
      urls.sort((a, b) => Number(b.match(/(\d+)\/$/)[1]) - Number(a.match(/(\d+)\/$/)[1]));
      let found = false;
      for (const url of urls) {
        const result = await read(url);
        const details = Object.fromEntries([...result.querySelectorAll('tr')]
          .filter(row => row.cells.length === 2)
          .map(row => [...row.cells].map(cell => cell.textContent.trim())));
        if (details['Sender:'] !== 'kaherrev' || details['Result:'] !== 'ACCEPTED') continue;
        const code = result.querySelector('pre.prettyprint');
        if (!code) throw new Error(`Missing source: ${url}`);
        exported.submissions.push({taskId, url, sender: details['Sender:'],
          verdict: details['Result:'], language: details['Language:'], code: code.textContent});
        console.log('Exported', taskId, url);
        found = true;
        break;
      }
      if (!found) throw new Error('No accepted submission found');
    } catch (error) {
      exported.errors.push({taskId, error: String(error)});
      console.error(taskId, error);
    }
  }
  const blob = new Blob([JSON.stringify(exported, null, 2)], {type: 'application/json'});
  const url = URL.createObjectURL(blob);
  const link = document.createElement('a');
  link.href = url;
  link.download = 'CSES-submissions.json';
  link.click();
  setTimeout(() => URL.revokeObjectURL(url), 60000);
  console.log(`Export complete: ${exported.submissions.length}/${tasks.length}`, exported.errors);
})();
