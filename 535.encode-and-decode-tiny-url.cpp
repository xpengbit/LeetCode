/*
 * @lc app=leetcode id=535 lang=cpp
 *
 * [535] Encode and Decode TinyURL
 */

// @lc code=start
class Solution {
public:
    Solution(){
        dict = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        long2short.clear();
        short2long.clear();
        srand(time(NULL));
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(long2short.count(longUrl))
            return "https://tinyurl.com/" + long2short[longUrl];
        
        string randstr;
        int index = 0;
        for(int i = 0; i < 6; ++i) randstr.push_back(dict[rand() % 62]);
        while(short2long.count(randstr)){
            randstr[index] = dict[rand() % 62];
            index = (index + 1) % 5;
        }

        short2long[randstr] = longUrl;
        long2short[longUrl] = randstr;

        return "https://tinyurl.com/" + randstr;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string randstr = shortUrl.substr(shortUrl.find_last_of("/"));
        return short2long.count(randstr) ? short2long[randstr] : shortUrl;
    }
private:
    unordered_map<string, string> long2short, short2long;
    stirng dict;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
// @lc code=end

