#include<iostream>

using namespace std;
class Hash
{
    private:
        int SIZE;
        int HSH_TABLE[];
    public:
        Hash(int s):SIZE(s)
        {
            for(int i=0;i<SIZE;i++)
                HSH_TABLE[i]=NULL;
        }
        int Getindex(int value);
        void insert(int value);
        void delete_value(int value);
        void find(int);
        void display_hashtable();
};
int Hash::Getindex(int value)
{
    return value%SIZE;
}
void Hash::insert(int value)
{
    int hv=Getindex(value);
    if(HSH_TABLE[hv]==NULL){
        HSH_TABLE[hv]=value;
        return;
    }
    else
    {
        for(int i=0;i<SIZE;i++)
        {
            int p=(hv+(i*i))%SIZE;
            if(HSH_TABLE[p]==NULL)
            {
                HSH_TABLE[p]=value;
                break;
            }
        }
    }
}
void Hash::delete_value(int value)
{
    int hv=Getindex(value);
    if(HSH_TABLE[hv]==value)
        HSH_TABLE[hv]=NULL;
    else{
        for(int i=0;i<=SIZE;i++)
        {
            int p=(hv+i*i)%SIZE;
            if(HSH_TABLE[p]==value)
            {
                HSH_TABLE[p]=NULL;
                break;
            }
        }
    }
}
void Hash::find(int value)
{
    int hv=Getindex(value);
    if(HSH_TABLE[hv]==value)
        cout<<"In hash table,"<<value<<" is present at index\n "<<hv;
    else{
            bool flag=false;
        for(int i=0;i<=SIZE;i++)
        {
            int p=(hv+(i*i))%SIZE;
            if(HSH_TABLE[p]==value)
            {
                cout<<"In hash table,"<<value<<" is present at index \n"<<p;
                flag=true;
                break;
            }
        }
        if(!flag)
             cout<<"In hash table,"<<value<<" is not found...\n";

    }
}
void Hash::display_hashtable()
{
    for(int i=0;i<SIZE;i++)
        cout<<i<<" -+> "<<HSH_TABLE[i]<<endl;
    cout<<endl;
}
int Choice()
{
    int choice;
    cout<<"::Enter option : ";
    cout<<"1. insertion\t\t";
    cout<<"2. deletion\t\t";
    cout<<"3. Searching\t\t";
    cout<<"4. display hashtable\t\t";
    cout<<"5. exit\t\n";
    cin>>choice;
    return choice;
}
int main()
{
    int val,n;
    cout<<"Enter size of HASH TABLE :";
    cin>>n;
    Hash hsh(n);
    while(true)
    {

        switch(Choice())
        {
            case 1:
                cout<<"Enter value that to be insert :";
                cin>>val;
                hsh.insert(val);
                break;
            case 2:
                cout<<"Enter value that to be delete :";
                cin>>val;
                hsh.delete_value(val);
                break;
            case 3:
            int i;
            cout<<"Enter number to be searched!\n";
            cin>>i;
            hsh.find(i);
            break;
            case 4:
                cout<<"\nHASH TABLE-->\n";
                hsh.display_hashtable();
                break;
            case 5:
                exit(0);
                break;
            default:
                cout<<"invalid index..........";
                cout<<endl;
                break;
        }
        
    }
}

