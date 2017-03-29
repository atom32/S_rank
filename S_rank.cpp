#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main() {
	int board[80][80],board_new[80][80],size_X,size_Y,counter=0;

	string line;
	cin>>size_X>>size_Y;
	//cout<<size_X<<" "<<size_Y;
	for(int x=0; x<size_X; x++) {
		cin>>line;
		//cout<<line;
		for(int y=0; y<size_Y; y++) {
			if(line[y]=='.') {
				board[x][y]=-1;
			} else if(line[y]=='#') {
				board[x][y]=-99;
			}
		}
	}
	for(int x=0; x<size_X; x++) {
		for(int y=0; y<size_Y; y++) {
			board_new[x][y]=0;;
		}
	}
	/*
	for(int x=0; x<size_X; x++) {
		for(int y=0; y<size_Y; y++) {
			cout<<board[x][y];
		}
		cout<<endl;
	}
	cout<<"So-so"<<endl;
	*/
	int start_X,start_Y,end_X,end_Y;
	int ans=0;
	start_X=0;
	start_Y=0;
	end_X=size_X-1;
	end_Y=size_Y-1;
	board[start_X][start_Y]=0;
	board_new[start_X][start_Y]=0;
	if(start_X==end_X&&start_Y==end_Y) {
		cout<<ans;
		return 0;
	}
	int touch=0;
	for(int i=1; i<size_X; i++) {
		if(touch==0) {
			if(board[start_X+i][start_Y]==-99) {
				touch=1;
			} else {
				board[start_X+i][start_Y]=0;
				board_new[start_X+i][start_Y]=0;
			}
		}
	}
	touch=0;
	for(int j=0; j<size_Y; j++) {
		if(touch==0) {
			if(board[start_X][start_Y+j]==-99) {
				touch=1;
			} else {
				board[start_X][start_Y+j]=0;
				board_new[start_X][start_Y+j]=0;
			}
		}
	}
	bool flag=false;
	while(!flag) {
		//cout<<counter<<endl;
		for(int x=0; x<size_X; x++) {
			for(int y=0; y<size_Y; y++) {
				if(board[x][y]==counter) {
					//cout<<x<<','<<y<<endl;
					touch=0;
					for(int i=1; (x+i)<size_X; i++) {
						if(touch==0) {
							if(board[x+i][y]==-99) {
								touch=1;
							} else if(board[x+i][y]==-1||board[x+i][y]>(counter+1)) {
								board_new[x+i][y]=counter+1;
							}
						}
					}
					touch=0;
					for(int j=1; (y+j)<size_Y; j++) {
						if(touch==0) {
							if(board[x][y+j]==-99) {
								touch=1;
							} else if(board[x][y+j]==-1||board[x][y+j]>(counter+1)) {
								board_new[x][y+j]=counter+1;
							}
						}
					}
					touch=0;
					for(int i=1; (x-i)>=0; i++) {
						if(touch==0) {
							if(board[x-i][y]==-99) {
								touch=1;
							} else if(board[x-i][y]==-1||board[x-i][y]>(counter+1)) {
								board_new[x-i][y]=counter+1;
							}
						}
					}
					touch=0;
					for(int j=1; (y-j)>=0; j++) {
						if(touch==0) {
							if(board[x][y-j]==-99) {
								touch=1;
							} else if(board[x][y-j]==-1||board[x][y-j]>(counter+1)) {
								board_new[x][y-j]=counter+1;
							}
						}
					}
					//getchar();
					for(int x=0; x<size_X; x++) {
						for(int y=0; y<size_Y; y++) {
							if(board_new[x][y]>0)board[x][y]=board_new[x][y];
							//cout<<board[x][y];
						}
						//cout<<endl;
					}
				}
			}
		}
		/*
		getchar();
		for(int x=0; x<size_X; x++) {
			for(int y=0; y<size_Y; y++) {
				cout<<board[x][y]<<" ";
			}
			cout<<endl;
		}
		*/
		counter++;
		if(board_new[end_X][end_Y]>0) {
			cout<<board_new[end_X][end_Y];
			return 0;
		}
	}

	return 0;
}

