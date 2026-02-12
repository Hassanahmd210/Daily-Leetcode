class Solution {
    public int longestBalanced(String s) {
        int maxLen = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                String sub = s.substring(i, j);
                
                if (sub.length() > maxLen && isBalanced(sub)) {
                    maxLen = sub.length();
                }
            }
        }
        return maxLen;
    }

    private boolean isBalanced(String sub) {
        int[] counts = new int[26];
        for (char c : sub.toCharArray()) {
            counts[c - 'a']++;
        }

        int targetCount = -1;
        for (int count : counts) {
            if (count > 0) {
                if (targetCount == -1) {
                    targetCount = count; 
                } else if (count != targetCount) {
                    return false;
                }
            }
        }
        return true;
    }
}