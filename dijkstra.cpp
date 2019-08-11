void dijkstra(vvpl& G, vl& dist, ll st){
    priority_queue<PL, vpl, greater<PL>> pq;
    dist[st] = 0;
    pq.push({0, st});
    while (!pq.empty()) {
        ll now = pq.top().ss, now_d = pq.top().ff; pq.pop();
        if(dist[now] < now_d) continue;
        for(PL& c : G[now]){
            if(dist[c.ff] > now_d + c.ss){
                dist[c.ff] = now_d + c.ss;
                pq.push({dist[c.ff], c.ff});
            }
        }
    }
}
