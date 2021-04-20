/*
 *
 * This code is copyrighted (c) 2021 by
 * Texas A&M Computer Science
 *
 *	There will be RIGOROUS cheat checking on your exams!!
 *	DON'T POST ANYWHERE!! such as CHEGG, public Github, etc
 *  You will be legally responsible.
 */

#include <string>
#include <stdexcept>
#include "User.h"
#include <cctype>
#include <iostream>

using std::string;
using std::vector;
using std::cout, std::endl;

User::User(string userName) : userName(userName), userPosts{} {
    // TODO(student): implement constructor checks
    if(userName.empty())
    {
        throw std::invalid_argument("userName is empty");
    }
    else if(!isalpha(userName.at(0)))
    {
        throw std::invalid_argument("userName doesn't begin with a letter");
    }
    for(int i = 0; i < userName.size(); i++)
    {
        if(isalpha(userName.at(i)) && isupper(userName.at(i)))
        {
            throw std::invalid_argument("not all letters are lowercase");
        }
    }
}

string User::getUserName() {
    // TODO(student): implement getter
    return userName;
}

vector<Post*>& User::getUserPosts() {
    // TODO(student): implement getter
    return userPosts;
}

void User::addUserPost(Post* post) {
    // TODO(student): add post to user posts
    if(post == nullptr)
    {
        throw std::invalid_argument("post pointer argumetn is a nullptr");
    }
    else
    {
        userPosts.push_back(post);
    }
}
