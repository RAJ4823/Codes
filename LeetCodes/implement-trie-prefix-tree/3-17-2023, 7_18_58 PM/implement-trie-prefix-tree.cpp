// Link: https://leetcode.com/problems/implement-trie-prefix-tree

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: implement-trie-prefix-tree
 *  RUNTIME: 73 ms
 *  MEMORY: 45.6 MB
 *  DATE: 3-17-2023, 7:18:58 PM
 *
 */

// Solution:




class TrieNode{
    public:
    bool endOfWord;
    TrieNode* children[26];       
    
    TrieNode()
    {
        endOfWord = false;
        for(int i = 0;i<26;i++){
            children[i] = NULL;   
        }
    }
};





class Trie {
public:

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* curr = root;
        
        for(int i = 0; i<word.size(); i++)
        {
            int index = word[i] - 'a';
            
            if(curr->children[index] == NULL)
                curr->children[index] = new TrieNode();
            curr = curr->children[index];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        
        
        for(int i = 0; i<word.size(); i++)
        {
            int index = word[i] - 'a';
            curr = curr->children[index];
            if(curr == NULL) return false;     
        }
        return curr->endOfWord;
    }

    bool startsWith(string prefix) {
        TrieNode* curr = root;
        
        for(int i = 0; i<prefix.size(); i++)
        {
            int index = prefix[i] - 'a';
            curr = curr->children[index];
            if(curr == NULL)
            {
                return false;                 
            }
        }
        return true;
        
    }
    
    ~Trie(){            
        clear(root);
    }
    
    void clear(TrieNode* root)
    {
        for(int i = 0; i<26; i++)
        {
            if(root->children[i] != NULL)
            {
                clear(root->children[i]);
            }
        }
        
        delete root;
    }

private:  //GOOD PRACTICE TO KEEP ROOT NODE PRIVATE
    TrieNode* root;
    

};

