class Solution {
public:
    bool isValid(string s) {
        stack <char> st ;
        unordered_map<char,char> hash = {{'{','}'},{'(',')'},{'[',']'}};
        bool inser =false,exi = false;
        if(s.size()%2==0 && (s[0]=='{' || s[0]=='('|| s[0]== '['))
        for(auto i : s)   
        {
            bool t = true;
            if(i=='{' || i=='('|| i== '[')
            {
                st.push(i);
                inser= true;
            }
            else
            {
                exi= true;
                if(!(st.empty())){
                if(hash[st.top()]!=i)
                {  cout<<"n";
                 t =false;

                }
                st.pop(); 
                
                if (t==false)
                    return false;
                }
                else
                    return false;
                    
                    
            }
        }
        else
            return false;
        if(inser == true && exi == true && st.empty()==true) 
            return true;
        else
            return false;
    }
};