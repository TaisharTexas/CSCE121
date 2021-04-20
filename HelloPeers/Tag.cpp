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
#include "Tag.h"
#include <cctype>

using std::string;
using std::vector;

Tag::Tag(string tagName) : tagName(tagName), tagPosts{} {
    // TODO(student): implement constructor checks
    if(tagName.size() < 2)
    {
        throw std::invalid_argument("tagName isn't long enough");
    }
    else if(tagName.at(0) != '#')
    {
        throw std::invalid_argument("tagName doesn't start with a #");
    }
    else if( !isalpha(tagName.at(1)) )
    {
        throw std::invalid_argument("tagName's second char isn't a letter");
    }

    for(int i = 1; i < tagName.size(); i++)
    {
        if(isalpha(tagName.at(i)))
        {
            if(isupper(tagName.at(i)))
            {
                throw std::invalid_argument("tagName has uppercase letters");
            }
        }
        else if(tagName.at(i) == ',' ||
                tagName.at(i) == '.' ||
                tagName.at(i) == '?' ||
                tagName.at(i) == '!')
        {
            throw std::invalid_argument("tagName has punctuation in it");
        }
    }
}

string Tag::getTagName() {
    // TODO(student): implement getter
    return tagName;
}

vector<Post*>& Tag::getTagPosts() {
    // TODO(student): implement getter
    return tagPosts;
}

void Tag::addTagPost(Post* post) {
    // TODO(student): add post to tag posts
    if(post == nullptr)
    {
        throw std::invalid_argument("post pointer argument is a nullptr");
    }
    else
    {
        tagPosts.push_back(post);
    }
}
