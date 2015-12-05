class Queue{
		private:
			int myArray *;
			int curSize;
			int curCapacity;

		public:
			Queue(int cap){
				myArray = malloc(sizeof(int) * cap);
				curCapacity = cap;
				curSize=0;
			}

			void enqueue(int x){ // O(1)
				if(curSize<curCapacity){
					myArray[curSize] = x;
					curSize++;
				}else{
					int tmp* = realloc(myArray,2*sizeof(int)* curCapacity)
					if(tmp == NULL){
						cout<<"Error in allocing more space"<<endl;
					}else{
						myArray = tmp;
						curCapacity = 2* curCapacity;
						myArray[curSize] = x;
						curSize++;
					}
				}
			}

			int dequeue(){ // O (N)
				int ret = -1;
				if(curSize!=-1){
					ret = myArray[0];
					for(int i=0,i<curSize-1;i++){
						myArray[i]= myArray[i+1];
					}
					curSize--;
				}else{
					cout<<"Empty Queue"<<endl;
				}
				return ret;
			}

			int getSize(){
				return curSize;
			}
};