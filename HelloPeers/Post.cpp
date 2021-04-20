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
#include <string>
#include <stdexcept>
#include "Post.h"
#include <cctype>

using std::string;
using std::vector;
using std::cout, std::endl;


Post::Post(unsigned int postId, string userName, string postText)
  : postId(postId), userName(userName), postText(postText) {
  if (postId == 0 || userName == "" || postText == "") {
    throw std::invalid_argument("post constructor: invalid parameter values");
  }
}

unsigned int Post::getPostId() {
  return postId;
}

string Post::getPostUser() {
  return userName;
}

string Post::getPostText() {
  return postText;
}

vector<string> Post::findTags() {
    // TODO(student): extracts candidate tags based on occurrences of # in the post
    vector<string> tags;       // the vector of tags found
    unsigned int tagStartIdx;  // starting index for the highlighted tag
    unsigned int tagEndIdx;    // end index for the highlighted tag
    unsigned int tagLength;    // the length of the highlighted tag
    string theTag;             // a temp string to hold each highlighted tag before it is added to the vector
    unsigned int currentStart = 0;  // the current location in postText

    unsigned int blah = string::npos;

    // iterate through postText finding tags, clearing them of ending special chars,
    // and adding them to the vector
    do
    {
        // find the start of the next tag
        tagStartIdx = postText.find('#', currentStart);
        // cout << "tag start: " << tagStartIdx << endl;

        if((postText.size() <= 1 && tagStartIdx != blah) )
        {
            theTag = postText;
            tags.push_back(theTag);
            tagStartIdx = blah;
            // cout << "post size was 1 and it is a #" << endl;
        }
        else
        {
            // cout << "entered else statement before getting tag end" << endl;
            if(tagStartIdx != blah)
            {
                //find the end of the tag
                tagEndIdx = postText.find(' ', tagStartIdx);
                // cout << "tag end: " << tagEndIdx << endl;

                if(tagEndIdx != blah)
                {
                    //calculate the length of the highlighted tag
                    tagLength  = (tagEndIdx - tagStartIdx);
                    // cout << tagLength << endl;
                    // pull out the highlighted tag
                    theTag = postText.substr(tagStartIdx, tagLength);
                    // cout <<"the Tag:" << theTag << endl;
                    // cout << theTag.size() << endl;
                }
                else
                {
                    theTag = postText.substr(tagStartIdx);
                    // cout << "THE ELSE STATEMENT" << endl;
                    // cout << theTag << endl;
                    tagStartIdx = blah;
                }
                if(theTag.size() > 1)
                {
                    // cout << "tag size was greater than 1" << endl;
                    bool clearedEnd = false;
                    // iterate through the highlighted tag and remove any ending special
                    // characters and convert all the letters to lowercase
                    for(int i = theTag.size()-1; i >= 0; i--)
                    {
                        // cout << i << endl;
                        // delete the end character if it is a special character
                        if( !isalpha(theTag.at(i)) && !clearedEnd )
                        {
                            theTag.pop_back();
                            // cout << "pops back value" << endl;
                        }
                        // convert the current char to lowercase and signify that the end has
                        // been cleared of special characters
                        else if( isalpha(theTag.at(i)) && !clearedEnd )
                        {
                            clearedEnd = true;
                            theTag.at(i) = tolower(theTag.at(i));
                            // cout << "goes to lower the first time" << endl;
                        }
                        // convert the current char to lowercase
                        else if( isalpha(theTag.at(i)) && clearedEnd )
                        {
                            theTag.at(i) = tolower(theTag.at(i));
                            // cout << "goes to lower every other time" << endl;
                        }
                    }
                }

                // cout << "makes it here? " << endl;

                //add the highlighted tag to the vector
                tags.push_back(theTag);
                // cout << "makes it here??" << endl;
                // updaate the current position in postText
                currentStart = tagEndIdx + 1;
            }
        }

        // cout << "tag start: " << tagStartIdx << endl;


        // cout << "what about here? " << endl;
    }
    while(tagStartIdx != blah);

    // cout << "finished finding tags" << endl;
    return tags;
}
