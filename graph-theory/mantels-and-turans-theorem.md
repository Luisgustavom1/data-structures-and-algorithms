## Forbidding a subgraph I: Mantel's theorem and Turán's theorem


##### Mantel's theorem
A triangle-free graph on N vertices <= n^2/4 edges

**PF1**
G = (V, E) with N vtx -> triangle-free

|V| = n
|E| = m

=> d(x) + d(y) <= n , xy e E
> onde d é o degree de G

=> SUM d(x)^2 = SUM(d(x) + d(y)) <= mn

=> SUM d(x) = 2m , então

=> 4m^2 = (SUM d(x))^2 <= n (SUM d(x)^2) <= mn^2

=> **m <= n^2/4**