import Queue from "./Queue";

export default function bfs(graph: WeightedAdjacencyMatrix, source: number, needle: number): number[] | null {
  const seen = new Array(graph.length).fill(false);
  const prev = new Array(graph.length).fill(-1);

  seen[source] = true;
  const q = new Queue<number>();
  q.enqueue(source);

  do {
    const curr = q.dequeue()!;
    if (needle === curr) {
      break;
    }

    const adjs = graph[curr];
    for (let i = 0; i < adjs.length; i++) {
      if (adjs[i] === 0 || seen[i]) continue;
      seen[i] = true;
      prev[i] = curr;
      q.enqueue(i);
    }
    
    seen[curr] = true;
  } while(q.length);

  let curr = needle;
  const out = [];
  while (prev[curr] !== -1) {
    out.push(curr)
    curr = prev[curr];
  }

  if (!out.length) return null;

  return [source].concat(out.reverse());
}