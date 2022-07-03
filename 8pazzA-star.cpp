#include<bits/stdc++.h>
using namespace std;

const int N=3;
vector<vector<int> >goal;///Goal state

struct node{///Storing each state of the tree
    vector<vector<int> >mat;
    int zi,zj;
    int level;
    node *parent;
    node(){
        mat.resize(N);
        for(int i=0; i<N; i++)mat[i].resize(N);
    }
};

///Create new node after a move
node *newNode(vector<vector<int> >mat,int zi,int zj,int x,int y,int level,node *parent){
    node *nd = new node();
    nd->parent = parent;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            nd->mat[i][j]=mat[i][j];
    swap(nd->mat[zi][zj], nd->mat[x][y]);
    nd->zi=x;
    nd->zj=y;
    nd->level=level;
    return nd;
}

///Direction vectors up/down/left/right
int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};


///Check is attempted move is within matrix bounds
bool safe(int i, int j){
    return (i>=0 && i<N && j>=0 && j<N);
}

bool isGoal(vector<vector<int> >&mat){
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)if(mat[i][j]!=goal[i][j])return 0;
    return 1;
}

void printMat(vector<vector<int> >&mat){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)cout<<mat[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

///Follow up the answer branch to the root and recursively print the matrices
void printPath(node *cur){
    if(cur->parent!=NULL)printPath(cur->parent);
    printMat(cur->mat);
}


///Heuristic function h(n)
int manhattan(vector<vector<int> >&mat){
        int ret=0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                for(int k=0; k<N; k++){
                    for(int l=0; l<N; l++){
                        if(mat[i][j]==goal[k][l])ret+=abs(k-i)+abs(l-j);
                    }
                }
            }
        }
        return ret;
    }

///Cost comparison
struct cmp{
    bool operator()(node *a, node *b){
        ///f(n)=h(n)+g(n)(level)
        return manhattan(a->mat)+a->level>manhattan(b->mat)+b->level;
    }

};

///Visited states
map<vector<vector<int> >,bool>vis;


void astar(vector<vector<int> >&mat){
    priority_queue<node*,vector<node*>,cmp>q;
    int zi,zj;
    for(int i=0; i<N; i++){///Find '0' position
        for(int j=0; j<N; j++){
            if(mat[i][j]==0){
                zi=i,zj=j;
                break;
            }
        }
    }
    node *root = newNode(mat,zi,zj,zi,zj,0,NULL);
    q.push(root);
    while(!q.empty()){
        node *top = q.top();
        q.pop();
        //printMat(top->mat);
        vis[top->mat]=1;
        if(isGoal(top->mat)){
            printPath(top);
            cout<<endl<<top->level<<" steps were needed to reach goal state"<<endl;
            return;
        }
        for(int i=0,xx,yy; i<4; i++){
            xx=top->zi+dx[i];
            yy=top->zj+dy[i];
            if(!safe(xx,yy))continue;
            node *nd=newNode(top->mat,top->zi,top->zj,xx,yy,(top->level)+1,top);
            if(!vis[nd->mat])q.push(nd);
        }
    }
    ///Queue empty with no solution
    cout<<"No solutions found"<<endl;
}

///Convert string to matrix
void string_to_mat(string &s, vector<vector<int> >&mat){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)mat[i][j]=s[(i*N)+j]-48;
    }
}


///Initialize the given matrix with a random state
void random_init(vector<vector<int> > &mat){
    int zi=0,zj=0;
    for(int i=0; i<N*N; i++){
        int x=rand()%N;
        int y=rand()%N;
        if(i==0){
                mat[x][y]=0;
                zi=x,zj=y;
                continue;
        }
        while((x==zi && y==zj) || mat[x][y])x=rand()%N,y=rand()%N;
        mat[x][y]=i;
    }
}

int inversions(vector<vector<int> >&mat){
    int arr[N*N];
    int x=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            arr[x++]=mat[i][j];
        }
    }
    int ret=0;
    for(int i=0; i<N*N; i++){
        for(int j=i+1; j<N*N; j++){
            if(arr[j] && arr[i]>arr[j])ret++;
        }
    }
    return ret;
}

int main(){
    srand(time(NULL));
    vector<vector<int> >mat(N,vector<int>(N));
    goal.resize(N,vector<int>(N));
    random_init(mat);
    random_init(goal);
    cout<<"Initial Matrix: "<<endl;
    printMat(mat);
    cout<<"----------------------\nGoal Matrix"<<endl;
    printMat(goal);
    cout<<"----------------------\n";
    if(inversions(mat)%2!=inversions(goal)%2)cout<<"No solutions possible"<<endl,exit(0);
    //string INITIAL_STATE = "867254301";
    //string GOAL_STATE    = "012345678";

    //string_to_mat(INITIAL_STATE,mat);
    //string_to_mat(GOAL_STATE,goal);
    astar(mat);
return 0;
}

