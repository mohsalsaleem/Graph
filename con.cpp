
    #include <iostream>

    #include <list>

    #include <queue>

    using namespace std;

    class Graph

    {

        private:

            int V;

            list<int> *adj;

        public:

            Graph(int V)

            {

                this->V = V;

                adj = new list<int>[V];

            }

            void addEdge(int v, int w);

            void BFS(int s, bool visited[]);

            Graph getTranspose();

            bool isConnected();

    };

     

    void Graph::addEdge(int v, int w)

    {

        adj[v].push_back(w);

        adj[w].push_back(v);

    }

     
   void Graph::BFS(int s, bool visited[])

    {

        list<int> q;

        list<int>::iterator i;

        visited[s] = true;

        q.push_back(s);

        while (!q.empty())

        {

            s = q.front();

            q.pop_front();

            for(i = adj[s].begin(); i != adj[s].end(); ++i)

            {

                if(!visited[*i])

                {

                    visited[*i] = true;

                    q.push_back(*i);

                }

            }

        }

    }


    Graph Graph::getTranspose()

    {

        Graph g(V);

        for (int v = 0; v < V; v++)

        {

            list<int>::iterator i;

            for(i = adj[v].begin(); i != adj[v].end(); ++i)

            {

                g.adj[*i].push_back(v);

            }

        }

        return g;

    }

   
    bool Graph::isConnected()

    {

        bool visited[V];

        for (int i = 0; i < V; i++)

            visited[i] = false;

        BFS(0, visited);

        for (int i = 0; i < V; i++)

            if (visited[i] == false)

                return false;

        Graph gr = getTranspose();

        for(int i = 0; i < V; i++)

            visited[i] = false;

        gr.BFS(0, visited);

        for (int i = 0; i < V; i++)

            if (visited[i] == false)

                return false;

        return true;

    }


    int main()

    {
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,u,v;
		cin>>n>>m;
        Graph g(n);
		for(int i=0;i<m;i++)
		{
		cin>>u>>v;
        g.addEdge(u, v);
        }

        if (g.isConnected())

            cout<<"The Graph is Connected"<<endl;

        else

            cout<<"The Graph is not Connected"<<endl;

     }

        
        return 0;

    }
