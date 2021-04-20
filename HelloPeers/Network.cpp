/*
 *
 * This code is copyrighted (c) 2021 by
 * Texas A&M Computer Science
 *
 *	There will be RIGOROUS cheat checking on your exams!!
 *	DON'T POST ANYWHERE!! such as CHEGG, public Github, etc
 *  You will be legally responsible.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Network.h"
#include <vector>

using std::string;
using std::vector;
using std::cout, std::endl, std::cin, std::istringstream, std::ifstream;

Network::Network() {
  // empty containers of vectors already created
  // no implementation is needed here
}

void Network::loadFromFile(string fileName) {
    // TODO(student): load user and post information from file
    if (fileName.size() < 4 || fileName.substr(fileName.length()-4, 4) != ".txt") throw std::invalid_argument("File not .txt file");

    ifstream ifs(fileName);
    if( !ifs.is_open() )
    {
        // cout << "threw invalid file" << endl;
        throw std::invalid_argument("invalid file name");
    }

    while(!ifs.eof())
    {
        string infoType;
        ifs >> infoType;
        // cout << "info type: " << infoType << endl;
        if(infoType == "User")
        {
            try
            {
                string userName;
                ifs >> userName;
                addUser(userName);
            }
            catch(const std::invalid_argument& e)
            {
                throw std::runtime_error("addUser() threw an exception");
            }
            catch(...)
            {
                throw std::runtime_error("error thrown while taking in user data from file");
            }
        }
        else if(infoType == "Post")
        {
            try
            {
                int postId;
                string postUser;
                string thePost;
                ifs >> postId >> postUser;
                getline(ifs, thePost);

                // cout << thePost << endl;
                if(thePost.at(0) == ' ')
                {
                    thePost = thePost.erase(0, 1);
                    // cout << "leading space char" << endl;
                }
                // cout << thePost << endl;

                // cout << " post Id: " << postId << endl;
                // cout << "postUser: " << postUser << endl;
                // cout << " thePost: " << thePost << endl;

                addPost(postId, postUser, thePost);
            }
            catch(const std::invalid_argument& e)
            {
                throw std::runtime_error("addPost() threw an exception");
            }
            catch(...)
            {
                throw std::runtime_error("error thrown while taking in post data from file");
            }

        }
        else if(infoType == "")
        {
            // cout << "blank" << endl;
        }
        else
        {
            throw std::runtime_error("invalid file formatting");
        }
    }


}

void Network::addUser(string userName) {
    // TODO(student): create user and add it to network
    if(users.size() > 0)
    {
        for(int i = 0; i < users.size(); i++)
        {
            if( userName == users.at(i)->getUserName() )
            {
                throw std::invalid_argument("name already exists in users");
            }
        }
    }

    User* newUser = new User(userName);
    users.push_back(newUser);
    cout << "Added User " << userName << endl;
}

void Network::addPost(unsigned int postId, string userName, string postText) {
    // TODO(student): create post and add it to network
    bool userExists = false;
    int userIdx;
    // cout << postText << endl;
    if(posts.size() > 0)
    {
        for(int i = 0; i < posts.size(); i++)
        {
            // cout << "first for loop in addPost" << endl;
            if(postId == posts.at(i)->getPostId())
            {
                // cout << "ID already exists error thrown" << endl;
                throw std::invalid_argument("post ID already exists");
            }
        }
    }
    for(int j = 0; j < users.size(); j++)
    {
        // cout << "second for loop in addPost" << endl;
        if(userName == users.at(j)->getUserName())
        {
            userExists = true;
            userIdx = j;
        }
    }
    // cout << "user exists? " << userExists << endl;
    if(userExists)
    {
        Post* newPost = new Post(postId, userName, postText);
        // cout << "created new post" << endl;
        posts.push_back(newPost);
        // cout << "pushed new post" << endl;
        users.at(userIdx)->addUserPost(newPost);
        // cout << "added new post to user profile" << endl;
        vector<string> tagsFromNewPost = newPost->findTags();
        // cout << "collected the tags from new post" << endl;
        // cout << "tags from posts size: " << tagsFromNewPost.size() << endl;

        for(int k = 0; k < tagsFromNewPost.size(); k++)
        {
            bool tagExists = false;
            for(int t = 0; t < tags.size(); t++)
            {
                if(tagsFromNewPost.at(k) == tags.at(t)->getTagName())
                {
                    tagExists = true;
                    tags.at(t)->addTagPost(newPost);
                }
            }
            if(!tagExists)
            {
                try
                {
                    Tag* newTag = new Tag(tagsFromNewPost.at(k));
                    // cout << "new tag: " << tagsFromNewPost.at(k) << endl;
                    newTag->addTagPost(newPost);
                    tags.push_back(newTag);
                }
                catch(const std::invalid_argument& e)
                {
                    cout << "Invalid Tag argument: " << e.what() << endl;
                }
            }

        }

        cout << "Added Post " << postId << " by " << userName << endl;
        // cout << "--------------------------------------------------" << endl;

    }
    else
    {
        // cout << "nonexistant user error thrown" << endl;
        throw std::invalid_argument("user doesn't exist yet");
    }
}

vector<Post*> Network::getPostsByUser(string userName) {
    // TODO(student): return posts created by the given user
    if(userName.empty())
    {
        throw std::invalid_argument("userName is empty");
    }
    for(int i = 0; i < users.size(); i++)
    {
        if(userName == users.at(i)->getUserName())
        {
            return users.at(i)->getUserPosts();
        }
    }
    throw std::invalid_argument("userName not found");
}

vector<Post*> Network::getPostsWithTag(string tagName) {
    // TODO(student): return posts containing the given tag
    if(tagName.empty())
    {
        throw std::invalid_argument("tagName is empty");
    }
    for(int i = 0; i < tags.size(); i++)
    {
        // cout << "i: " << i << endl;
        // cout << "tags.at(i): " << tags.at(i)->getTagName() << endl;
        if(tagName == tags.at(i)->getTagName())
        {
            return tags.at(i)->getTagPosts();
        }
    }
    throw std::invalid_argument("tagName not found");
}

vector<string> Network::getMostPopularHashtag() {
    // TODO(student): return the tag occurring in most posts
    vector<string> mostPopularTag;

    int max = tags.at(0)->getTagPosts().size();
    mostPopularTag.push_back(tags.at(0)->getTagName());

    for(int i = 1; i < tags.size(); i++)
    {
        if(tags.at(i)->getTagPosts().size() > max)
        {
            max = tags.at(i)->getTagPosts().size();
            mostPopularTag.clear();
            mostPopularTag.push_back(tags.at(i)->getTagName());
        }
        else if(tags.at(i)->getTagPosts().size() == max)
        {
            mostPopularTag.push_back(tags.at(i)->getTagName());
        }
    }
    return mostPopularTag;
}

/**
  * Destructor
  * Do not change; already implemented.
  */
Network::~Network() {
  for (unsigned int i = 0; i < users.size(); ++i) {
    delete users.at(i);
  }
  for (unsigned int i = 0; i < tags.size(); ++i) {
    delete tags.at(i);
  }
  for (unsigned int i = 0; i < posts.size(); ++i) {
    delete posts.at(i);
  }
}
