#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

//Prototypes
void fixSingleDomainCell(vector<vector<unordered_set<int>>> &, vector<vector<int>> &);
void reduceDomain(vector<vector<unordered_set<int>>> &, vector<vector<int>> &, int, int, int);

int gridSize, numOfNodes;
vector<vector<int>> solved_board;

void initialize_domain( vector<vector<unordered_set<int>>> &domain, vector<vector<int>> &board, int i, int j)    {
    unordered_set<int> initial_domain;
    for(int num=1;num<=gridSize;++num) {
        initial_domain.insert(num);
    }
    //Row Check
    for(int col = 0;col<gridSize;++col)    {
        initial_domain.erase(board[i][col]);
    }
    //Col Check
    for(int row = 0;row<gridSize;++row)    {
        initial_domain.erase(board[row][j]);
    }
    //Box Check
    int root = sqrt(gridSize);
    int row = i - i%root, col = j - j%root;
    for(int r = row;r<row+root;++r)    {
        for(int c = col;c<col+root;++c)    {
            initial_domain.erase(board[r][c]);
        }
    }
    domain[i][j] = initial_domain;
    return;
}

void fixSingleDomainCell(vector<vector<unordered_set<int>>> &domain, vector<vector<int>> &board)    {
    for(int i=0;i<gridSize;++i)    {
        for(int j = 0;j<gridSize;++j)  {
            if(domain[i][j].size()==1)  {
                auto it = domain[i][j].begin();
                board[i][j] = *it;
                reduceDomain(domain, board, i, j, *it);
            }
        }
    }
    return;
}   

void reduceDomain(vector<vector<unordered_set<int>>> &domain, vector<vector<int>> &board, int i, int j, int digit)  {

    //Row Check
    for(int col = 0;col<gridSize;++col)    {
        domain[i][col].erase(digit);
    }
    //Col Check
    for(int row = 0;row<gridSize;++row)    {
        domain[row][j].erase(digit);
    }
    //Box Check
    int root = sqrt(gridSize);
    int row = i - i%root, col = j - j%root;
    for(int r = row;r<row+root;++r)    {
        for(int c = col;c<col+root;++c)    {
            domain[r][c].erase(digit);
        }
    }

    //Indirect Recursion
    fixSingleDomainCell(domain, board);
}

vector<vector<int>> deepCopyBoard(vector<vector<int>> &board)   {
    vector<vector<int>> board_copy(gridSize, vector<int>(gridSize));
    for(int i=0;i<gridSize;++i) {
        for(int j = 0;j<gridSize;++j)   {
            board_copy[i][j] = board[i][j];
        }
    }
    return board_copy;
}

vector<vector<unordered_set<int>>> deepCopyDomain(vector<vector<unordered_set<int>>> &domain) {
    vector<vector<unordered_set<int>>> domain_copy(gridSize, vector<unordered_set<int>>(gridSize));
    for(int i=0;i<gridSize;++i)    {
        for(int j = 0;j<gridSize;++j)  {
            for(auto it = domain[i][j].begin();it!=domain[i][j].end();++it) {
                domain_copy[i][j].insert(*it);
            }
        }
    }
    return domain_copy;
}

bool solveCSP(vector<vector<int>>& board, int i, int j, vector<vector<unordered_set<int>>>& domain)   {
    if(i==gridSize) {
        return true;
    }
    if(j==gridSize)    return solveCSP(board, i+1, 0, domain);
    if(board[i][j]!=0)    return solveCSP(board, i, j+1, domain);
    for(auto it = domain[i][j].begin();it!=domain[i][j].end();++it)   {
            numOfNodes+=2;
            auto board_copy = deepCopyBoard(board);
            auto domain_copy = deepCopyDomain(domain);
            board[i][j] = *it;
            reduceDomain(domain, board, i, j, *it);
            if(solveCSP(board, i, j+1, domain))    {
                return true;
            }
            board = deepCopyBoard(board_copy);
            domain = deepCopyDomain(domain_copy);
    }
    return false;
}

int main() {
    vector<vector<int>> board = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                                {6, 0, 0, 1, 9, 5, 0, 0, 0},
                                {0, 9, 8, 0, 0, 0, 0, 6, 0},
                                {8, 0, 0, 0, 6, 0, 0, 0, 3},
                                {4, 0, 0, 8, 0, 3, 0, 0, 1},
                                {7, 0, 0, 0, 2, 0, 0, 0, 6},
                                {0, 6, 0, 0, 0, 0, 2, 8, 0},
                                {0, 0, 0, 4, 1, 9, 0, 0, 5},
                                {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    gridSize = board.size(), numOfNodes = 0;

    if(ceil(sqrt(gridSize))!=floor(sqrt(gridSize))) {
        cout<<"Cannot Solve";
        return 0;
    }

    vector<vector<unordered_set<int>>> domain(gridSize, vector<unordered_set<int>>(gridSize));
    solved_board.resize(gridSize, vector<int>(gridSize));

    //Initializing domain for each cell
    for(int i=0;i<gridSize;++i)    {
        for(int j = 0;j<gridSize;++j)  {
            if(board[i][j]==0)
                initialize_domain(domain, board, i, j);
        }
    }


    cout<<"\nBefore Solving"<<endl;
    for(auto row : board)   {
        for(auto cell : row) cout<<cell<<" ";
        cout<<endl;
    }

    auto start = high_resolution_clock::now();
    solveCSP(board, 0, 0, domain);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    cout<<"\nNumber of nodes needed "<<numOfNodes<<endl;
    cout<<"Time taken to solve : "<<duration.count()<<" μs"<<endl;
    cout<<"\nAfter Solving"<<endl;
    for(auto row : board)   {
        for(auto cell : row) cout<<cell<<" ";
        cout<<endl;
    }
    return 0;
}