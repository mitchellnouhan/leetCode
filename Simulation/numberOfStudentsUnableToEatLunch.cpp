class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        //int res = 0;
        int stu_circle = 0;
        int stu_square = 0;
        for(int stu: students){
            if(stu == 0){
                stu_circle++;
            }
            else{
                stu_square++;
            }
        }
        
        while (!sandwiches.empty() && !((sandwiches[0] == 0 && stu_circle == 0) || (sandwiches[0] == 1 && stu_square == 0))){
            int student = students[0];
            int sandwich = sandwiches[0];
            // student likes sandwich
            if(student == sandwich){
                students.erase(students.begin());
                sandwiches.erase(sandwiches.begin());
                if(student){
                    stu_square--;
                }
                else{
                    stu_circle--;
                }
            }
            // student doesn't like sandwich
            else{
                students.erase(students.begin());
                students.push_back(student);
            }
        }
        return sandwiches.size();
    }
};

/*
exit condition
-top of sandwich stack is 0 and stu_circle == 0 OR
top of sandwich stack is 1 and stu_square == 0
    return students.size

-stack is empty
    return 0

stu_circle = 2
stu_square = 4
students = [1,1,1,0,0,1], sandwiches = [1,0,0,0,1,1]

students   = [1,1,1,0,0,1]
sandwiches = [1,0,0,0,1,1]


*/