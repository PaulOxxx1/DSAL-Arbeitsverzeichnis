bool isBipartit(list adj[n]){
	queue q;
	q.enqueue(1);
	while(!q.empty()){
		u = q.dequeue();
		foreach v in adj[u]{
			if(!v.color){
				if(u.color == red)	v.color = black;
				else			v.color = red;
				q.enqueue(v);
			} else if (v.color == u.color) return false;
		}	
	}
	return true;
}