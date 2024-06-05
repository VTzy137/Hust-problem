#include<bits/stdc++.h>
using namespace std;
struct node{
	int v;
	node *n;
	node(int v1, node* n1){
		v = v1;
		n = n1;
	}
};
node *s[10005], *ds[100005] = {};
int n, m, u, v, p = 0, coun = 0;
int x[10005] = {}, scc[10005] = {};
bool visited[10005], come[10005], dem[100005];
void duyet(int u){
	node *tmp = s[u];
	while(tmp){
		if(!visited[tmp->v]){
			visited[tmp->v] = true;
			come[tmp->v] = true;
			x[++p] = tmp->v;
			duyet(tmp->v);
			--p;
			come[tmp->v] = false;
		}
		else if(come[tmp->v] || scc[tmp->v]){
            int i = 0;
            for(i; i <= p; ++i){
                if(scc[tmp->v] == scc[x[i]])
                    break;
            }
            if(come[tmp->v])
                i = 0;
            if(i <= p){
                int tmp1 = scc[tmp->v];
                if(!scc[tmp->v])
                    tmp1 = ++coun;
                for(int i = p; i >= 0; --i){
                    if(scc[x[i]] && scc[x[i]] != tmp1){
                        node *tmp3 = ds[scc[x[i]]];
                        while(tmp3){
                            ds[tmp1] = new node(tmp3->v, ds[tmp1]);
                            scc[tmp3->v] = tmp1;
                            tmp3 = tmp3->n;
                        }
                        ds[scc[x[i]]] = 0;
                    }
                    else if(scc[x[i]] != tmp1){
                        ds[tmp1] = new node(x[i], ds[tmp1]);
                        scc[x[i]] = tmp1;
                    }
                    if(x[i] == tmp->v)
                        break;
                }
            }
		}
		tmp = tmp->n;
	}
}

int main(){
    // freopen("test.txt", "r", stdin);
	cin >> n >> m;
	while(m--){
		scanf("%d%d", &u, &v);
		s[u] = new node(v, s[u]);
	}
	int i = 1;
	while(1){
		for(i; i <= n; ++i)
			if(!visited[i])
				break;
		if(i > n)
			break;
		visited[i] = true;
		come[i] = true;
		x[0] = i;
		duyet(i);
		come[i] = false;
	}
	coun = 0;
	for(i = 1; i <= n; ++i){
		if(scc[i])
			dem[scc[i]] = true;
		else{
			++coun;
	    	// cout << i << " " << scc[i] << endl;
	    }
    }
    // cout << coun << endl;
	for(i = 1; i <= 100000; ++i)
		if(dem[i]){
			++coun;
			// cout << i << " ";
		}
	cout << coun;
}
