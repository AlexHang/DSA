
class PriorityQueue{
private:
    AdvancedStack distances;
    AdvancedStack auxStk;
    room rooms[100];
    int head,tail;
public:
    PriorityQueue(){
        head=tail=0;
    };
    int isEmpty(){
        if(head==tail)
            return 1;
        else return 0;
    }


    void enQueue(int r, double d){
            rooms[(tail)%100].name=r;
            rooms[(tail)%100].distance=d;
            tail++;
            distances.push(d);
    }
    int deQueue(){
        int nr,index;
        double mini=distances.getMin();
        //cout<<mini;
       // cout<<mini;
       for(int i=head;i<tail;i++){
            if(rooms[i].distance>=mini-0.01 && rooms[i].distance<=mini+0.01){
               // cout<<rooms[i].name;
                nr=rooms[i].name;
                index=i;
            }

       }
       for (int i = index; i < tail-1; i++)
            rooms[i] = rooms[i + 1]; // copy next element left
        tail--;


        while(distances.isEmpty()!=1){
                if(distances.peek()>=mini-0.01 && distances.peek()<=mini+0.01)
                    distances.pop();
                else{
                    auxStk.push(distances.peek());
                    distances.pop();
                }
        }
        while(auxStk.isEmpty()!=1){
            distances.push(auxStk.peek());
            auxStk.pop();
        }

        return nr;
    }


    int peek(){

         double mini=distances.getMin();
        //cout<<mini;
       // cout<<mini;
           for(int i=head;i<tail;i++){
                if(rooms[i].distance>=mini-0.01 && rooms[i].distance<=mini+0.01){
                   // cout<<rooms[i].name;
                    return rooms[i].name;
                }

           }

    }

};
