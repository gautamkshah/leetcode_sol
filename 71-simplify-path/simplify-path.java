class Solution {
    public String simplifyPath(String path) {
        int n = path.length();
        StringBuilder res = new StringBuilder();
        Stack<String> st = new Stack<>();
        
        for (int i = 0; i < n; i++) {
            if (path.charAt(i) == '/') continue;
            
            StringBuilder temp = new StringBuilder();
            while (i < n && path.charAt(i) != '/') {
                temp.append(path.charAt(i));
                i++;
            }
            
            String dir = temp.toString();
            if (dir.equals(".")) continue;
            else if (dir.equals("..")) {
                if (!st.isEmpty()) st.pop();
            } else {
                st.push(dir);
            }
        }
        
        while (!st.isEmpty()) {
            res.insert(0, st.pop());
            res.insert(0, "/");
        }
        
        if (res.length() == 0) {
            return "/";
        }
        
        return res.toString();
    }
}