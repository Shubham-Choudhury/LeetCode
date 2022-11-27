// Link: https://leetcode.com/problems/design-authentication-manager/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class AuthenticationManager {
public:
    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        tokens[tokenId] = currentTime + ttl;
    }
    
    void renew(string tokenId, int currentTime) {
        if (tokens.find(tokenId) != tokens.end() && tokens[tokenId] > currentTime) {
            tokens[tokenId] = currentTime + ttl;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int result = 0;
        for (auto& token : tokens) {
            if (token.second > currentTime) {
                result++;
            }
        }
        return result;
    }

private:
    int ttl;
    unordered_map<string, int> tokens;
};

int main() {
    AuthenticationManager* obj = new AuthenticationManager(5);
    obj->generate("aaa", 1);
    obj->renew("aaa", 6);
    cout << obj->countUnexpiredTokens(6) << endl;
    obj->renew("aaa", 10);
    cout << obj->countUnexpiredTokens(15) << endl;
    return 0;
}