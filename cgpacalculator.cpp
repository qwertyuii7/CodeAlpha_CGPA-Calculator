#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
class gpa{
    public:
    float caclciGPA(){
        int totalsems;
        cout<<"enter the number of semesters:";
        cin >> totalsems;
        double totalgradepoint_all = 0;  // For CGPA
        double totalcredit_all = 0;
        float cgpa = 0;
        for (int sem = 1; sem <= totalsems; ++sem){
            int total_course;
            cout<<"enter the number of totalcourse";
            cin>>total_course;
            vector<string> grade(total_course);
            vector <int> credits(total_course);
            vector <int> gradepoints(total_course);

            map<string, int> gradeToPoint;
            gradeToPoint["A+"] = 10;
            gradeToPoint["A"] = 9;
            gradeToPoint["B+"] = 8;
            gradeToPoint["B"] = 7;
            gradeToPoint["C"] = 6;
            gradeToPoint["D"] = 5;
            gradeToPoint["F"] = 0;
            vector<int> points(total_course);
            double totalcredit=0;
            double totalgradepoint=0;
            cout << "\n Subject-wise Details:\n";
            cout << "------------------------------------------\n";
            cout << "Subject\tGrade\tCredit\tGrade Point\n";
            cout << "------------------------------------------\n";

        

            for(int i=0;i<total_course;++i){
                cout<<"enter the grade for your "<<i+1<<" subject :";
                cin>>grade[i];
                transform(grade[i].begin(), grade[i].end(), grade[i].begin(), ::toupper);
                cout<<"enter the credit for your "<<i+1<<" subject :";
                cin>>credits[i];


                totalcredit=totalcredit+credits[i];
                if(gradeToPoint.count(grade[i])){
                    points[i]=gradeToPoint[grade[i]];
                }else{
                    cout <<"Invalid grade. Please enter a valid grade like A+, B+, etc.\n";
                    points[i]=0;
                }


            
                totalgradepoint+=(points[i]*credits[i]);
                cout << i + 1 << "\t" << grade[i] << "\t" << credits[i] << "\t" << points[i] << "\n";
            }
            float gpa = 0;
            if (totalcredit != 0) {
                gpa = totalgradepoint / totalcredit;
                cout << "------------------------------------------\n";
                cout << " GPA for Semester " << sem << ": " << gpa << "\n";
            } else {
                cout << " No valid credits entered for Semester " << sem << "\n";
                continue;
            }

            
            totalcredit_all += totalcredit;
            totalgradepoint_all += totalgradepoint;

            
            
            if (totalcredit_all != 0) {
                cgpa = totalgradepoint_all / totalcredit_all;

                if (totalsems == 1) {
                    cout << "\n🎓 Since only 1 semester, GPA = CGPA = " << cgpa << "\n";
                } else {
                    cout << "\n🎓 Final CGPA after " << totalsems << " semesters is: " << cgpa << "\n";
                }
            } else {
                cout << "\n Cannot calculate CGPA (no valid credits entered).\n";
            }
             
        }
        if (totalcredit_all != 0) {
            cgpa = totalgradepoint_all / totalcredit_all;

            if (totalsems == 1) {
                cout << "\n🎓 Since only 1 semester, GPA = CGPA = " << cgpa << "\n";
            } else {
                cout << "\n🎓 Final CGPA after " << totalsems << " semesters is: " << cgpa << "\n";
            }
        } else {
            cout << "\n Cannot calculate CGPA (no valid credits entered).\n";
        }
        return cgpa;
                 
    }
    
};
int main(){
    
    
    gpa obj;
    obj.caclciGPA();


    return 0;
 
}