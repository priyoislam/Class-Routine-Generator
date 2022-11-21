#include <bits/stdc++.h>
using namespace std;
int arr[30];
string S[]= {"1st year","2nd year","3rd year","4th year","Masters"};
int cn[10][2] = { {5,5}, {6,7}, {8,9},{7,5},{5,5} };
struct courses
{
    string name;
    string shurt;
    string code;
    string tch;
    int year,b;
    int d1,d2;
    int t1,t2;


} crs[10][10][20];

struct teachers
{
    string name;
    string st;
    struct courses xyz[10];
    int e;
    int pri;


} teach[20] ;
struct Class
{
    struct courses x;
    struct teachers z;

} cls[6][6][6];

struct Class resch[100];
int rindex=0;
void teacher();
void crsdet();
void asign();
void routine();
void delay(int n)
{
    int count=0;
    double i;
    for(i=0; i<n; i+=0.00001)
        count=0;
}
void line()
{
    for(int i=1; i<75; i++)
    {
        cout<<"--";
    }


    cout<<"\n";
}

void star()
{
    for(int i=1; i<75; i++)
    {
        cout<<"**";

    }

    cout<<"\n";
}
void print()
{
    cout<<"\n\n\n";
    cout<<endl<<setw(70)<<"Class Routine\n"<<endl;
    line();
    star();
    line();
    cout<<setw(8)<<"Day"<<setw(8)<<"|"<<setw(17)<<"8.30-9.50"<<setw(17)<<"|"<<setw(17)
        <<"10.00-11.20"<<setw(17)<<"|"<<setw(17)<<"11.30-12.50"<<setw(17)<<"|"<<setw(17)<<"2.00-4.30\n";
    line();
    string day[]= {"Sunday   ","Monday   ","Tuesday  ","Wednesday","Thursday "};
    for(int i=1; i<=5; i++)
    {
        cout <<"   " <<day[i-1] <<setw(4);
        for(int j=1; j<=4; j++)
        {

            cout << " |";
            for(int k=1; k<=2; k++)
            {
                cout<<"  "<<cls[i][j][k].x.code;
                if(cls[i][j][k].z.st.length()==2)
                {
                    cout<< "( ";
                }
                else
                {
                    cout<< "(";
                }
                cout <<cls[i][j][k].z.st;
                if(cls[i][j][k].z.st.length()<4)
                {
                    cout<< " ) ";
                }
                else
                {
                    cout<<") ";
                }
                if(k==1)
                {
                    cout << ", " ;
                }

            }
           // if(j<3){cout<<setw(2);}

        }
        cout <<endl<<setw(16);
        for(int j=1; j<=4; j++)
        {
            cout << " |";
            for(int k=3; k<=4; k++)
            {
                cout<<"  "<<cls[i][j][k].x.code;
                if(cls[i][j][k].z.st.length()==2)
                {
                    cout<< "( ";
                }
                else
                {
                    cout<< "(";
                }
                cout <<cls[i][j][k].z.st;
                if(cls[i][j][k].z.st.length()<4)
                {
                    cout<< " ) ";
                }
                else
                {
                    cout<<") ";
                }
                if(k==3)
                {
                    cout << ", " ;
                }


            }
            //if(j<3){cout<<setw(2);}
        }
        cout<<endl;
        line();
    }
    star();
    line();



}
void wi()
{
    cout << "\n\nWrong input !!! Please give right information.\n";
}


void rsch();



void setup(int p);



int main()
{
    crsdet();
    teacher();
    for(int i=1; i<6; i++)
    {
        for(int j=1; j<5; j++)
        {
            for(int k=1; k<5; k++)
            {
                cls[i][j][k].x.shurt= {"EMPTY"};
                cls[i][j][k].x.code= {"      "};
                cls[i][j][k].z.st= {"    "};
            }
        }
    }

    star();
    string b[10]= {"Welcome to Class Routine Generator"};
    cout <<endl<<endl<<setw(30);

    for(int j=0; j<b[0].length(); j++)
    {
        cout << b[0][j];
        delay(50);
    }
    cout<<endl;

    while(1)
    {
        cout<<endl<<setw(50)<<"Main Menu\n";
        cout << "\nPlease select an option :\n\n1.Assign Courses to Teachers\n\n2.Teacher's Schedule Selection\n\n";
        cout << "3.Rescheduled Courses Selection\n\n4.Print Routine\n\n5.Exit\n\n";
        cout<<"Your Option :";
        char k;
        cin >> k;
        k=(int)k-48;

        switch (k)
        {
        case 1 :
            asign();
            break;
        case 2 :
            routine();
            break;
        case 3 :
            rsch();
            break;
        case 4 :
            print();
            break;
        case 5 :
        {
            string g[] = {"Program is exiting"};
            cout<<endl<<endl<<setw(40);
            for(int i=0; i<g[0].length(); i++)
            {
                cout<<g[0][i];
                delay(50);
            }
            cout<<endl<<endl;
            return 0;
        }

        default :
            cout<<endl<<endl<<setw(60);
            cout << "Please select an appropriate option.\n";
            break;
        }

    }


    return 0;
}
void asign()
{
    for(int i=0;i<15;i++){teach[i].e=0;}
    cout << "\n\nFor which semester you want to assign teachers ?\nOption 1. First semester\nOption 2. Second semester\n\n";
    char  z;
    while(1)
    {
        cout<< "Please Select Your Option : ";
        cin >> z;
        z=(int)z-48;

        if(z<1 || z>2)
        {
            wi();
        }
        else
        {
            break;
        }
    }
    cout<<"\n\n1.Assign Teachers Manually\n2.Assign Teachers Default\n\nPlease select your option:";
    int x=0;
    while(x!=1)
    {

        char l;
        cin >>l;
        l=(int)l-48;
        switch(l)
        {
        case 1 :
        {
            x=1;
            cout << "Assign Courses to teacher :\n\nYou have to only give teacher code.\n";
            for(int i=0; i<5; i++)
            {
                cout <<endl<<endl<< S[i] <<":\n";
                for(int j=1; j<=cn[i][z-1] ; j++)
                {
                    cout << crs[i+1][z][j].name << ": ";
                    cin >>crs[i+1][z][j].tch;
                    cout<<endl;
                    int k=0;
                    while(teach[k].st != crs[i+1][z][j].tch)
                    {
                        k++;
                        if(k>14)
                        {
                            cout << "Teacher code is wrong.\nPlease give correct teacher code :";
                            cin >>crs[i+1][z][j].tch;
                            k=0;
                        }
                    }
                    teach[k].xyz[teach[k].e] = crs[i+1][z][j];
                    teach[k].e++;
                }
            }
        }
        break;
        case 2 :
        {
            x=1;
            int m=0;
            string t[]= {"KMA","FKP","MSI","FKP","MSI","MAY","RM","SR","MAY","RM","SR",
                         "JA","WZ","SAM","FT","MSK","JA","WZ","FT","MMS","RTK","MBTN","NZZ",
                         "MSK","MMS","RTK","MBTN","SR","MAY","WZ","NZZ",
                        };
            for(int i=0; i<5; i++)
            {

                for(int j=1; j<=cn[i][z-1] ; j++)
                {
                    crs[i+1][z][j].tch=t[m];
                    m++;
                    int k=0;
                    while(teach[k].st != crs[i+1][z][j].tch)
                    {
                        k++;
                    }
                    teach[k].xyz[teach[k].e] = crs[i+1][z][j];
                    teach[k].e++;
                }

            }
            for(int i=0; i<5; i++)
            {
                for(int j=1; j<=cn[i][z-1] ; j++)
                {
                    cout << crs[i+1][z][j].name << ": ";
                    cout<<crs[i+1][z][j].tch;
                    cout<<endl;

                }
            }
        }
        break;

        default :
        {
            cout<<endl<<endl<<setw(60);
            cout << "Please select an appropriate option.\n";
        }
        }
    }


    cout << "\n\nAll courses are assigned to teachers.\n\n";

}
void routine()
{
    cout << "\nThere is three available time slot for theory courses\n\n1 - 8.30 to 9.50 am\n";
    cout << "2 - 10.00 to 11.20 am \n3 - 11.30 to 12.50 pm\n\nIf it is a lab course then the time slot is\n";
    cout << "4 - 2.00 to 4.45\n\n";
    cout << "A teacher have to take 2 classes per week for each theory courses \nand 1 class for lab courses\n\n";
    cout <<"You can select any two of the following day slot:\n";

    cout << "1. Sunday 2.Monday 3. Tuesday 4. Wednesday 5. Thursday\n\n";
    cout << "Now we are requesting teachers to give their preferred time and date :\n";


    string a;
    int b=0,c=0;
    int arr[15]= {0};
    while(b!=1)
    {
        int i;
        cout << "Please give teacher code : ";
        cin >> a;
        for(i=0; i<15; i++)
        {
            if(a==teach[i].st)
            {
                arr[i]=1;
                setup(i);

                b=1;
                break;
            }

        }
        if(i==15)
        {
            cout << "\n\nYour Teacher Code is wrong . Please give right input.\n\n";
        }

    }


}
void setup (int p)
{
    cout << "\n\nYou are " << teach[p].name <<endl;
    if(teach[p].e==0)
    {
        cout << "\n\nCurrently you have not assigned to any course.\n\n\n";
    }
    else
    {
        cout << "\nYou have following courses :\n\n";
        int cnt;
        for(int i=0; i<teach[p].e; i++)
        {

            cout << teach[p].xyz[i].code << " :" << teach[p].xyz[i].name<<endl;



        }
        int ll=0;
        while(ll!=1)
        {
            cout<< "\nPlease select an option:\n1.See partially filled routine.\n";
            cout<<"2.Complete my schedule\n3.Return to main menu\n\nYour option :";
            char v;
            cin >> v;
            v=(int)v-48;

            switch (v)
            {
            case 1 :
            {
                print();
                break;
            }
            case 2 :
            {
                cnt=0;
                for(int i=0; i<teach[p].e; i++)
                {
                    int d,d1,d2,h1,h2,h;
                    if(teach[p].xyz[i].b==0)
                    {

                        cout << "\n\nPlease give preferred day and time for your corresponding courses.\n";
                        if((teach[p].xyz[i].code[5]-48)%2==0)
                        {
                            int loop=0;
                            while(loop!=1)
                            {

                                loop=0;
                                cout <<teach[p].xyz[i].code << ": day = " ;
                                cin >> d1;
                                if(d1<1 || d1>5)
                                {
                                    wi();
                                }
                                else
                                {
                                    int k=0;

                                    for(int j=1; j<5; j++)
                                    {
                                        if(cls[d1][4][j].z.st==teach[p].st)
                                        {
                                            cout<< "\n\nYou have another class at this hour.Please select another day\n\n";
                                            loop=2;
                                            break;
                                        }
                                        else if(cls[d1][4][j].x.year==teach[p].xyz[i].year )
                                        {
                                            if(teach[p].pri>0)
                                            {

                                                cout << "\nThis batch has another class in this day.";
                                                cout << "Do you want to replace the scheduled class?\n1.Yes\n2.No\nResponse :";

                                                cin>> k;
                                                if(k==2)
                                                {
                                                    loop=2;

                                                }
                                                else if(k==1)
                                                {

                                                    loop=1;
                                                    resch[rindex++]=cls[d1][4][j];
                                                    //rindex++;
                                                    cls[d1][4][j].x=teach[p].xyz[i];
                                                    cls[d1][4][j].z=teach[p];
                                                    teach[p].xyz[i].b=1;
                                                    teach[p].pri=teach[p].pri-1;
                                                    cout<< "\nYour class is added to the routine. Thank you\n";
                                                }
                                            }
                                            else if( teach[p].pri==0)
                                            {
                                                loop=2;
                                                cout << "\n\nClasses are full or You can not replace any more class as you have already replaced two classes\n";
                                                cout<<"Please select another day.\n\n";
                                            }
                                            break;
                                        }
                                    }

                                    if(loop == 0)
                                    {
                                        for(int z=1; z<5; z++)
                                        {
                                            if(cls[d1][4][z].x.shurt=="EMPTY")
                                            {

                                                cls[d1][4][z].x=teach[p].xyz[i];
                                                cls[d1][4][z].z=teach[p];
                                                teach[p].xyz[i].b=1;
                                                loop=1;
                                                cout<< "\nYour class is added to the routine. Thank you\n\n";
                                                break;
                                            }
                                            else if(z==4 && teach[p].pri>0)
                                            {
                                                cout << "There is no free classroom available\n";
                                                cout << "Do you want to replace the scheduled class?\n1.Yes\n2.No\nResponse :";
                                                cin >>k;
                                                if(k==1)
                                                {

                                                    resch[rindex++]=cls[d1][4][z];
                                                    //rindex++;
                                                    cls[d1][4][z].x=teach[p].xyz[i];
                                                    cls[d1][4][z].z=teach[p];
                                                    teach[p].xyz[i].b=1;
                                                    teach[p].pri--;
                                                    loop=1;
                                                    cout<< "\nYour class is added to the routine. Thank you\n\n";

                                                }
                                            }
                                            else if( z==4 && teach[p].pri==0)
                                            {
                                                loop=2;
                                                cout << "\n\nClasses are full or You can not replace any more class as you have already replaced two classes\n";
                                                cout<<"Please select another day.\n\n";
                                            }

                                        }
                                    }


                                }
                            }


                        }
                        else
                        {
                            int loop=0, k;
                            d2=1;
                            while(d2<3)
                            {
                                loop=0;
                                while(loop!=1)
                                {
                                    loop=0;
                                    int fg=0;
                                    while(fg!=2)
                                    {
                                        fg=0;
                                        cout << teach[p].xyz[i].code << ":   day " << d2 << ":";
                                        cin >> d1;
                                        if(d1<1 || d1>5)
                                        {
                                            wi();
                                        }
                                        else
                                        {
                                            for(int f=1; f<4; f++)
                                            {
                                                for(int g=1; g<5; g++)
                                                {
                                                    if(cls[d1][f][g].x.shurt==teach[p].xyz[i].shurt)
                                                    {
                                                        cout << "This course is already assigned on this day.Please select another day :"<<endl;
                                                        fg=1;
                                                        break;
                                                    }
                                                }
                                                if(fg==1)
                                                {
                                                    break;
                                                }
                                            }
                                            if(fg!=1)
                                            {
                                                fg=2;
                                            }
                                        }
                                    }
                                    cout << "time slot : ";
                                    cin >> h1;
                                    if((d1<1 || d1>5)|| (h1<1 || h1>3))
                                    {
                                        wi();

                                    }
                                    else
                                    {
                                        for(int y=1; y<5; y++)
                                        {
                                            if(cls[d1][h1][y].z.st==teach[p].st)
                                            {
                                                cout<< "\n\nYou have another class at this hour.Please select another day\n\n";
                                                loop=2;
                                                break;
                                            }
                                        }
                                        if(loop!=2)
                                        {


                                            for(int y=1; y<5; y++)
                                            {
                                                if(cls[d1][h1][y].x.year==teach[p].xyz[i].year )
                                                {
                                                    if(teach[p].pri>0)
                                                    {
                                                        cout << "\n\nThis batch has another class in this time\n";
                                                        cout << "Do you want to replace the scheduled class?\n1.Yes\n2.No\nResponse :";

                                                        cin>> k;
                                                        if(k==2)
                                                        {
                                                            loop=2;

                                                        }
                                                        else if(k==1)
                                                        {
                                                            resch[rindex++]=cls[d1][h1][y];
                                                            //rindex++;
                                                            cls[d1][h1][y].x=teach[p].xyz[i];
                                                            cls[d1][h1][y].z=teach[p];
                                                            teach[p].xyz[i].b=1;
                                                            teach[p].pri--;
                                                            loop=1;
                                                            cout<< "\nYour class is added to the routine. Thank you\n\n";
                                                        }
                                                    }

                                                    else if( teach[p].pri==0)
                                                    {
                                                        loop=2;
                                                        cout << "\n\nClasses are full or You can not replace any more class as you have already replaced two classes\n";
                                                        cout<<"Please select another day.\n\n";
                                                    }
                                                    break;

                                                }
                                            }
                                        }


                                        if(loop == 0)
                                        {
                                            for(int z=1; z<5; z++)
                                            {
                                                if(cls[d1][h1][z].x.shurt=="EMPTY")
                                                {

                                                    cls[d1][h1][z].x=teach[p].xyz[i];
                                                    cls[d1][h1][z].z=teach[p];
                                                    teach[p].xyz[i].b=1;
                                                    loop=1;
                                                    cout<< "\nYour class is added to the routine. Thank you\n\n";
                                                    break;
                                                }
                                                else if(z==4 && teach[p].pri>0)
                                                {
                                                    cout << "\nThere is no free classroom available\n";
                                                    cout << "Do you want to replace the scheduled class?\n1.Yes\n2.No\nResponse :";
                                                    cin >>k;
                                                    if(k==2)
                                                    {
                                                        break;
                                                    }
                                                    else if(k==1)
                                                    {
                                                        resch[rindex++]=cls[d1][h1][z];
                                                        cls[d1][h1][z].x=teach[p].xyz[i];
                                                        cls[d1][h1][z].z=teach[p];
                                                        teach[p].xyz[i].b=1;
                                                        teach[p].pri--;
                                                        loop=1;
                                                        cout<< "\nYour class is added to the routine. Thank you\n\n";

                                                    }
                                                }
                                                else if( z==4 && teach[p].pri==0)
                                                {
                                                    loop=2;
                                                    cout << "\n\nClasses are full or You can not replace any more class as you have already replaced two classes\n";
                                                    cout<<"Please select another day.\n\n";
                                                }

                                            }
                                        }

                                    }

                                }
                                d2++;
                            }


                        }
                    }
                    if(teach[p].xyz[i].b==1)
                    {
                        cnt++;
                    }



                }

                if(cnt==teach[p].e)
                {
                    cout << "\n\nYou have completed schedule of all your courses.\n\n";
                }


                break;
            }

            case 3 :
            {

                ll=1;
                break;
            }
            default :
                cout<<endl<<endl<<setw(60);
                cout << "\nPlease select an appropriate option.\n\n";

            }
        }


    }
}



void rsch()
{

    cout <<endl;
    star();
    cout<<endl;
    if(rindex==0)
    {
        cout<< endl<< setw(62)<<"There are no classes to reschedule\n";
    }
    else
    {
        cout<< "\n\nFollowing courses are being requested to reschedule : "<<endl<<endl;
        for(int i=0; i<rindex; i++)
        {


            cout<<endl<< resch[i].x.code << " " <<resch[i].x.name<<"("<<resch[i].z.name<<")"<<endl<<endl;
            int f=0;
            while(f!=1)
            {


                cout<< "\nPlease select an option:\n1.See partially filled routine.\n";
                cout<<"2.Select schedule\n\nYour option : ";
                char h;
                cin >> h;
                h=(int)h-48;
                if(h==1)
                {
                    print();
                }
                else if(h==2)
                {
                    cout<< "\nPlease select an appropriate time and date from empty classes :\n";
                    int d,h,fg=0;
                    while(fg!=2)
                    {
                        fg=0;
                        cout << "day : ";
                        cin>>d;
                        if(resch[i].x.code[5]%2==0){h=4;}
                        else{
                        cout<<"hour :" ;
                        cin>>h;}
                        if((d<1 || d>5)||(h<1 ||h>4)){wi();}
                        else
                        {



                        for(int f=1; f<4; f++)
                        {
                            for(int g=1; g<5; g++)
                            {
                                if(cls[d][f][g].x.shurt==resch[i].x.shurt)
                                {
                                    cout << "\nThis course is already assigned on this day. Please select another day."<<endl;
                                    fg=1;
                                    break;
                                }
                            }
                            if(fg==1)
                            {
                                break;
                            }
                        }
                        if(fg!=1)
                        {
                            for(int y=1; y<5; y++)
                            {
                                if(cls[d][h][y].z.st==resch[i].z.st)
                                {

                                    cout<< "\nYou have another class at this hour.Please select another day.\n";
                                    fg=1;
                                    break;
                                }
                                else if(cls[d][h][y].x.year==resch[i].x.year)
                                {
                                    cout << "\nThis batch has another class at this hour.Please select another day.\n";
                                    fg=1;
                                    break;
                                }
                            }
                        }
                        if(fg!=1)
                        {
                            for(int y=1; y<5; y++)
                            {
                                if(cls[d][h][y].x.shurt=="EMPTY")
                                {
                                    cls[d][h][y]=resch[i];
                                    fg=2;
                                    cout<< "\nYour class is added to the routine. Thank you\n\n";
                                    break;
                                }
                            }
                            if(fg!=2)
                            {
                                cout << "\nNo class is empty .Please select another day\n";
                            }
                        }

                    }
                    f=1;}
                }
                else
                {
                    cout<<endl<<endl<<setw(60);
                    cout << "\nPlease select an appropriate option.\n\n";
                }
            }
        }
        rindex=0;
    }
}

void teacher()
{
    teach[0].name="M. Mesbahuddin Sarkar";
    teach[1].name="Md. Fazlul Karim Patwary";
    teach[2].name="M. Khan Mohammad Akkas Ali";
    teach[3].name="Dr. Md. Wahiduzzaman";
    teach[4].name="Dr. M Shamim Kaiser";
    teach[5].name="Fahima Tabassum";
    teach[6].name="Jesmin Akhter";
    teach[7].name="Risala Tasin Khan";
    teach[8].name="Dr. Mohammad Abu Yousuf";
    teach[9].name="Dr. Shamim Al Mamun";
    teach[10].name="Dr. Mohammad Shahidul Islam";
    teach[11].name="Dr. Sazadur Rahman";
    teach[12].name="Dr. Rashed Mazumder";
    teach[13].name="Manan Binth Taj Noor";
    teach[14].name="Nusrat Zerin Zenia";


    teach[0].st="MMS";
    teach[1].st="FKP";
    teach[2].st="KMA";
    teach[3].st="WZ";
    teach[4].st="MSK";
    teach[5].st="FT";
    teach[6].st="JA";
    teach[7].st="RTK";
    teach[8].st="MAY";
    teach[9].st="SAM";
    teach[10].st="MSI";
    teach[11].st="SR";
    teach[12].st="RM";
    teach[13].st="MBTN";
    teach[14].st="NZZ";
    for(int i=0; i<15; i++)
    {
        teach[i].e=0;
        teach[i].pri=2;
    }

}

void crsdet()
{
    crs[1][1][1].name = "Information Technology Fundamentals";
    crs[1][1][1].shurt = "ITF";
    crs[1][1][1].code = "IT1101";

    crs[1][1][2].name = "Introduction to Programming Environment";
    crs[1][1][2].shurt = "IPE";
    crs[1][1][2].code = "IT1103";

    crs[1][1][3].name = "Electrical Circuits";
    crs[1][1][3].shurt = "EC";
    crs[1][1][3].code = "IT1105";

    crs[1][1][4].name = "Structured Programming Language Lab";
    crs[1][1][4].shurt = "IPE Lab";
    crs[1][1][4].code = "IT1104";

    crs[1][1][5].name = "Electrical Circuits Lab";
    crs[1][1][5].shurt = "EC Lab";
    crs[1][1][5].code = "IT1106";
    //1.1 done

    crs[1][2][1].name = "Data Structures";
    crs[1][2][1].shurt = "DS";
    crs[1][2][1].code = "IT1201";

    crs[1][2][2].name = "Object Oriented Programming";
    crs[1][2][2].shurt = "OOP";
    crs[1][2][2].code = "IT1203";

    crs[1][2][3].name = "Discrete Math";
    crs[1][2][3].shurt = "DM";
    crs[1][2][3].code = "IT1205";

    crs[1][2][4].name = "Data Structures Lab";
    crs[1][2][4].shurt = "DS Lab";
    crs[1][2][4].code = "IT1202";

    crs[1][2][5].name = "Object Oriented Programming Lab";
    crs[1][2][5].shurt = "OOP Lab";
    crs[1][2][5].code = "IT1204";
    //1.2 done
    for(int i=1; i<3; i++)
    {
        for(int j=1; j<6; j++)
        {
            crs[1][i][j].year=1;
        }
    }

    crs[2][1][1].name = "Algorithm Analysis";
    crs[2][1][1].shurt = "AA";
    crs[2][1][1].code = "IT2101";

    crs[2][1][2].name = "Computer Architecture";
    crs[2][1][2].shurt = "CA";
    crs[2][1][2].code = "IT2103";

    crs[2][1][3].name = "Electronic Devices and Circuits";
    crs[2][1][3].shurt = "EDC";
    crs[2][1][3].code = "IT2105";

    crs[2][1][4].name = "Algorithm Analysis Lab";
    crs[2][1][4].shurt = "AA Lab";
    crs[2][1][4].code = "IT2102";

    crs[2][1][5].name = "Computer Architecture Lab";
    crs[2][1][5].shurt = "CA Lab";
    crs[2][1][5].code = "IT2104";

    crs[2][1][6].name = "Electronic Devices and Circuits Lab";
    crs[2][1][6].shurt = "EDC Lab";
    crs[2][1][6].code = "IT2106";
    //2.1 done
    for(int j=1; j<7; j++)
    {
        crs[2][1][j].year=2;
    }
    crs[2][2][1].name = "Information System Analysis";
    crs[2][2][1].shurt = "ISA";
    crs[2][2][1].code = "IT2201";

    crs[2][2][2].name = "Digital Logic Design";
    crs[2][2][2].shurt = "DLD";
    crs[2][2][2].code ="IT2203";

    crs[2][2][3].name = "Data Communication";
    crs[2][2][3].shurt = "DC";
    crs[2][2][3].code = "IT2205";

    crs[2][2][4].name = "Computational Mathematics";
    crs[2][2][4].shurt = "CM";
    crs[2][2][4].code = "IT2209";

    crs[2][2][5].name = "Information System Analysis lab";
    crs[2][2][5].shurt = "ISA Lab";
    crs[2][2][5].code = "IT2202";

    crs[2][2][6].name = "Digital Logic Design Lab";
    crs[2][2][6].shurt = "DLD Lab";
    crs[2][2][6].code = "IT2204";

    crs[2][2][7].name = "Computational Mathematics Lab";
    crs[2][2][7].shurt = "CM Lab";
    crs[2][2][7].code = "IT2210";
    for(int j=1; j<8; j++)
    {
        crs[2][2][j].year=2;
    }
    crs[3][1][1].name = "Database Management System";
    crs[3][1][1].shurt = "DMS";
    crs[3][1][1].code = "IT3101";

    crs[3][1][2].name = "Computer Network and Internet Technology";
    crs[3][1][2].shurt = "CNIT";
    crs[3][1][2].code = "IT3103";

    crs[3][1][3].name = "Signal and System";
    crs[3][1][3].shurt = "SAS";
    crs[3][1][3].code = "IT3105";

    crs[3][1][4].name = "Operating System";
    crs[3][1][4].shurt = "OS";
    crs[3][1][4].code = "IT3107";

    crs[3][1][5].name = "Simulation and Modeling";
    crs[3][1][5].shurt = "SM";
    crs[3][1][5].code = "IT3109";

    crs[3][1][6].name = "Database Management System Lab";
    crs[3][1][6].shurt = "DMS Lab";
    crs[3][1][6].code = "IT3102";

    crs[3][1][7].name = "Computer Network and Internet Technology Lab";
    crs[3][1][7].shurt = "CNIT Lab";
    crs[3][1][7].code = "IT3104";

    crs[3][1][8].name = "Operating System Lab";
    crs[3][1][8].shurt = "OS Lab";
    crs[3][1][8].code = "IT3108";

    for(int j=1; j<9; j++)
    {
        crs[3][1][j].year=3;
    }
    crs[3][2][1].name = "Software Engineering";
    crs[3][2][1].shurt = "SE";
    crs[3][2][1].code = "IT3201";

    crs[3][2][2].name = "Computer Graphics";
    crs[3][2][2].shurt = "CG";
    crs[3][2][2].code = "IT3203";

    crs[3][2][3].name = "Web Technologies";
    crs[3][2][3].shurt = "WT";
    crs[3][2][3].code = "IT3205";

    crs[3][2][4].name = "Microprocessor and Interfacing";
    crs[3][2][4].shurt = "MAI";
    crs[3][2][4].code = "IT3207";

    crs[3][2][5].name = "Introduction to Bio-informatics";
    crs[3][2][5].shurt = "IBI";
    crs[3][2][5].code = "IT3209";

    crs[3][2][6].name = "Software Engineering Lab";
    crs[3][2][6].shurt = "SE Lab";
    crs[3][2][6].code = "IT3202";

    crs[3][2][7].name = "Computer Graphics Lab";
    crs[3][2][7].shurt = "CG Lab";
    crs[3][2][7].code = "IT3204";

    crs[3][2][8].name = "Web Programming Lab";
    crs[3][2][8].shurt = "WP Lab";
    crs[3][2][8].code = "IT3206";

    crs[3][2][8].name = "Microprocessor and Interfacing Lab";
    crs[3][2][8].shurt = "MAI Lab";
    crs[3][2][8].code = "IT3208";

    for(int j=1; j<10; j++)
    {
        crs[3][2][j].year=3;
    }
    crs[4][1][1].name = "Artificial Intelligences & Neural Networks";
    crs[4][1][1].shurt = "AINN";
    crs[4][1][1].code = "IT4101";

    crs[4][1][2].name = "Telecommunication Systems";
    crs[4][1][2].shurt ="TCS";
    crs[4][1][2].code = "IT4103";

    crs[4][1][3].name = "Management Information System";
    crs[4][1][3].shurt = "MIS";
    crs[4][1][3].code = "IT4105";

    crs[4][1][4].name = "Parallel and Distributed System";
    crs[4][1][4].shurt = "PDS";
    crs[4][1][4].code = "IT4107";

    crs[4][1][5].name = "Multimedia Systems & Application";
    crs[4][1][5].shurt = "MSA";
    crs[4][1][5].code = "IT4109";

    crs[4][1][6].name = "Artificial Intelligences & Neural Networks Lab";
    crs[4][1][6].shurt = "AINN Lab";
    crs[4][1][6].code = "IT4102";

    crs[4][1][7].name = "Telecommunication Systems Lab";
    crs[4][1][7].shurt = "TCS Lab";
    crs[4][1][7].code = "IT4104";
    for(int j=1; j<8; j++)
    {
        crs[4][1][j].year=4;
    }

    crs[4][2][1].name = "Human Computer Interfacing";
    crs[4][2][1].shurt = "HCI";
    crs[4][2][1].code = "IT4201";

    crs[4][2][2].name = "Wireless & Mobile Communication";
    crs[4][2][2].shurt = "WMC";
    crs[4][2][2].code = "IT4203";

    crs[4][2][3].name = "Digital Image Processing and Pattern Recognition";
    crs[4][2][3].shurt = "DIP";
    crs[4][2][3].code = "IT4225";

    crs[4][2][4].name = "Computer Network Security";
    crs[4][2][4].shurt = "CNS";
    crs[4][2][4].code = "IT4259";

    crs[4][2][5].name = "Mobile application development";
    crs[4][2][5].shurt = "MAD";
    crs[4][2][5].code = "IT4227";
    for(int j=1; j<6; j++)
    {
        crs[4][2][j].year=4;
    }
    crs[5][1][1].name = "Advanced Database Systems";
    crs[5][1][1].shurt = "ADS";
    crs[5][1][1].code = "IT5101";

    crs[5][1][2].name = "Probability & Stochastic Process ";
    crs[5][1][2].shurt ="PSP";
    crs[5][1][2].code = "IT5102";

    crs[5][1][3].name = "Advanced Digital Communication ";
    crs[5][1][3].shurt = "ADC";
    crs[5][1][3].code = "IT5103";

    crs[5][1][4].name = "Advanced Optical Communication ";
    crs[5][1][4].shurt = "AOC";
    crs[5][1][4].code = "IT5109";

    crs[5][1][5].name = "Information System Simulation & Modeling";
    crs[5][1][5].shurt = "ISSM";
    crs[5][1][5].code = "IT5111";
    for(int j=1; j<6; j++)
    {
        crs[5][1][j].year=5;
    }
    crs[5][2][1].name = "Advanced Mobile & Cellular Communication Technologies";
    crs[5][2][1].shurt = "AMCCT";
    crs[5][2][1].code = "IT5201";

    crs[5][2][2].name = "Microwave Communication Systems";
    crs[5][2][2].shurt ="MCS";
    crs[5][2][2].code = "IT5202";

    crs[5][2][3].name = "Telecommunication Network Management";
    crs[5][2][3].shurt = "TNM";
    crs[5][2][3].code = "IT5203";

    crs[5][2][4].name = "E-Commerce & E-Governance";
    crs[5][2][4].shurt = "ECG";
    crs[5][2][4].code = "IT5210";

    crs[5][2][5].name = "Advanced Software Engineering";
    crs[5][2][5].shurt = "ASE";
    crs[5][2][5].code = "IT5219";
    for(int j=1; j<6; j++)
    {
        crs[5][2][j].year=5;
    }
    for(int i=1; i<6; i++)
    {
        for(int j=1; j<3; j++)
        {
            for(int k=1; k<10; k++)
            {
                crs[i][j][k].b=0;
            }

        }
    }

}
