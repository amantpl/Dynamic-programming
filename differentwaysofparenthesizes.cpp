class Solution {
public:
vector<int> solve(string& expression,int i,int j){
    vector<int> ans;
    
    string numstr=expression.substr(i,j-i+1);
    bool isnumber=true;
    for(char c:numstr){
        if(!isdigit(c)){
            isnumber=false;
            break;
        }
    }

    if(isnumber){
        int num=stoi(numstr);
        ans.push_back(num);
        return ans;
    }

    for(int k=i;k<=j;k++){
        if(expression[k]=='-' || expression[k]=='+' || expression[k]=='*'){
        vector<int> left=solve(expression,i,k-1);
        vector<int> right=solve(expression,k+1,j);

        for(int lt:left){
            for(int rt:right){
                if(expression[k]=='-'){
                    ans.push_back(lt-rt);
                }else if(expression[k]=='+'){
                    ans.push_back(lt+rt);
                }else if(expression[k]=='*'){
                    ans.push_back(lt*rt);
                }
            }
        }
        }
    }
    return ans;

}
    vector<int> diffWaysToCompute(string expression) {
        int n=expression.size();
        int i=0;
        int j=n-1;
        return solve(expression,i,j);
        
    }
};