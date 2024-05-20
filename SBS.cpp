#include<iostream>
#include <string.h>
#include <fstream>
#include <sstream>
using namespace std;
class Node{
    public:
        int data;
        int x,y,sum;        //x == quantity
        string name,nam;    //y == price
        Node *prev,*next;
};
class System :public Node
{
public:
    Node *head,*last;
    System()
    {
        head=NULL;
        last=NULL;
    }
   Node* create_node()
    {
        Node *temp = new Node;
        cout<<"ENTER PRODUCT ID: "<<endl;
        cin>>temp->data;
        cout<<"ENTER PRODUCT NAME: "<<endl;
        cin>>temp->name;
        cout<<"ENTER QUANTITY: "<<endl;
        cin>>temp->x;
        cout<<"ENTER PRICE OF EACH PRODUCT: "<<endl;
        cin>>temp->y;
        temp->next = NULL;
        temp->prev = NULL;
        return temp;
    }
    void insert_node(){
        Node *temp=new Node;
        temp = create_node();
        if(head == NULL){
            head = temp;
            last=temp;
        }
        else{
            last->next=temp;
            temp->prev=last;
            last=temp;
        }
    }
    void add_begin(){
        Node *temp=new Node;
        temp = create_node();
        temp->next = head;
        head->prev = temp;
        head=temp;
    }
     void add_last(){
        Node *temp=new Node;
        temp = create_node();
        temp->prev = last;
        last->next = temp;
        last=temp;
        last->next=NULL;
     }
    void add_any_position(){
        Node *temp=new Node;
        temp= create_node();
        int position,count=1;
        cout<<"Enter the position at which the product has to be inserted :"<<endl;
        cin>>position;
        Node *previous,*current;
        current= head;
        while(position!=count){
            previous=current;
            current=current->next;
            count++;
        }
        if(position==count)
            {
               previous->next=temp;
               temp->next=current;
               temp->prev=previous;
               current->prev=temp;
            }
        cout<<"Product inserted at the given position"<<endl;
    }
    void display(){
        Node *product;
        product  = head;
        system("cls");
        cout<<"\n\n\t\t\t**********************ALL MART STORE*****************************"<<endl;
        cout<<"\nPRODUCT ID\t"<<"PRODUCT NAME\t"<<"QUANTITY\t"<<"PRICE"<<endl;
        while(product!=NULL){
            cout<<product->data<<"\t\t";
            cout<<product->name<<"\t\t";
            cout<<product->x<<"\t\t";
            cout<<product->y<<"\n";
            product = product->next;
        }
    }
    void delete_beg(){
        Node *temp;
        temp = head;
        head = head->next;
        cout<<temp->data<<" has been deleted"<<endl;
        delete(temp);
    }
    void delete_end(){
        Node *product;
        product = head;
        while(product->next != NULL){
            product = product->next;
        }
        product->prev->next = NULL;
        cout<<product->data<<" has been deleted"<<endl;
        delete(product);
    }
    void delete_after(){
        int value;
        cout<<"Enter the product after which the node has to be deleted"<<endl;
        cin>>value;
        Node *product;
        product = head;
        while(product->data != value){
            product = product->next;
        }
        Node *temp;
        temp = product->next;
        product->next = temp->next;
        temp->next->prev = product;
        cout<<temp->data<<" has been deleted"<<endl;
        delete(temp);
    }
    void buy(){
        system("cls");
        string products[20];
        int pay=0,no,c=0,price,id,i=1;
        if(head==NULL) {
            cout<<"\n<<<<There is no items to buy>>>>\n\n";
        }
        else{
            cout<<"How many items you wanna to buy!\n";
            cin>>no;
			int count= display1();
            while (i<=no){
			Node *cur=head;
            int quant,choice;
            cout<<"Enter id of item number "<<i<<" that you want to buy: \n";
            int id,pos=0;
            cin>>id;
            pos=search(id);
           if(pos<=count){
               while(cur->data!=id){
                   cur=cur->next;
                }
                cout<<"How many quantities you want: \n";
                cin>>quant;
                products[c]=cur->name;
                c=c+1;
                pay=pay+(cur->y*quant);
                cur->x=cur->x-quant;
                i++;
            }
            else
                cout<<"\n<<<<<<<<<This item is not available in our store at this time>>>>\n\n";
            }
        system("cls");
        cout<<"\n\n\n\t\t\tYou have bought : ";
        for(int i=0;i<no;i++){
            cout<<products[i]<<",";
        }
        price=pay*(0.95);
        cout<<"\n\nOriginal price : "<<pay;
        cout<<"\n with 5% discount: "<<price<<"\nThank you! for the shopping\n\n";
    }
}
    int search(int id)
    {
        int count=1;
        Node *p=head;
        while(p!=NULL)
        {
            if(p->data==id)
                break;
            else {
                count++;
                p=p->next;
            }
        }
        return count;
}

    int display1(){
        system("cls");
        int c=0;
        Node *p=head;
        cout<<"Existing products are:\n";
        cout<<"ID\t\tProduct Name\t\tPrice\t\tQuantity\n";
        while(p!=NULL)
            {
			cout<<p->data<<"\t\t"<<p->name<<"\t\t\t"<<p->y<<"\t\t"<<check(p->x)<<"\n";
			p=p->next;
			c++;
		}
        cout<<"\nTotal products in our store is : "<<c<<"\n\n\n";
        return c;
}
    string check(int quant){
    int a = quant;
    stringstream ss;
    ss << a;
    string quantity = ss.str();
    if(quant<=0)
    return "out of stock!";
    else
    return quantity;
}

    void srch(){
        system("cls");
        cout<<"\n\n\t\t\t**********************ALL MART STORE*****************************\n\n\n"<<endl;
        string nam;
        cout<<"Enter Product Name "<<endl;
        cin>>nam;
        int f=0;
        Node *p=head;
        while(p!=NULL)
        {
            if(nam==p->name)
            {
                f=1;
                break;
            }
        else
 			p=p->next;
        }
        if(f==1)
            cout<<"Product is available"<<endl;
        else
            cout<<"Out of Stock"<<endl;
  }

};

// MAIN FUNCTION
int main(){
    System ob;
    int option;
    do{
        cout<<"-------------------------------------------------------------"<<endl;
        cout<<"1 ADD PRODUCT"<<endl;
        cout<<"2 ADD PRODUCT AT FIRST POSITION"<<endl;
        cout<<"3 ADD PRODUCT AT LAST POSITION"<<endl;
        cout<<"4 ADD PRODUCT AFTER A GIVEN POSITION"<<endl;
        cout<<"5 DELETE PRODUCT AT LAST POSITION"<<endl;
        cout<<"6 DELETE PRODUCT AT FIRST POSITION"<<endl;
        cout<<"7 DELETE PRODUCT AT AFTER A GIVEN POSITION"<<endl;
        cout<<"8 DISPLAY"<<endl;
        cout<<"9 BUY"<<endl;
        cout<<"10 SEARCH"<<endl;
        cin>>option;
            switch(option){
                case 1: ob.insert_node();
                        break;
                case 2: ob.add_begin();
                        break;
                case 3: ob.add_last();
                        break;
                case 4: ob.add_any_position();
                        break;
                case 5: ob.delete_end();
                        break;
                case 6: ob.delete_beg();
                        break;
                case 7: ob.delete_after();
                        break;
                case 8: ob.display();
                        break;
                case 9: ob.buy();
                        break;
                case 10: ob.srch();
                        break;
                default:
                    cout<<" Invalid Choice"<<endl;
                    break;
            }

    }while(option != 0);

return 0;
}

