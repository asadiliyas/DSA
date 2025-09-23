class Solution {
public:
    int compareVersion(string version1, string version2) {

        int n1 = version1.size();
        int n2 = version2.size();

        int i1 = 0, i2 = 0;

        while(i1 < n1 && i2 < n2){

            string temp1 = "";

            while(version1[i1] != '.' && i1 < n1){
                temp1 += version1[i1];
                i1++;
            }

            int num1 = stoi(temp1);

            string temp2 = "";

            while(version2[i2] != '.' && i2 < n2){
                temp2 += version2[i2];
                i2++;
            }

            int num2 = stoi(temp2);

            if(num1 < num2){
                return -1;
            }

            if(num1 > num2){
                return 1;
            }

            i1++;
            i2++;

        }

        while(i1 < n1){

            string temp1 = "";

            while(version1[i1] != '.' && i1 < n1){
                temp1 += version1[i1];
                i1++;
            }

            int num1 = stoi(temp1);

            if(num1 > 0){
                return 1;
            }

            i1++;

        }

        while(i2 < n2){

            string temp2 = "";

            while(version2[i2] != '.' && i2 < n2){
                temp2 += version2[i2];
                i2++;
            }

            int num2 = stoi(temp2);

            if(num2 > 0){
                return -1;
            }

            i2++;

        }

        return 0;

    }
};
