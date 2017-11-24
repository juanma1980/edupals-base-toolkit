/*
 * Copyright (C) 2017 Edupals project
 *
 * Author:
 *  Enrique Medina Gremaldos <quiqueiii@gmail.com>
 *
 * Source:
 *  https://github.com/edupals/edupals-base-toolkit
 *
 * This file is a part of edupals-base-toolkit.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 */
 
#include <cmd.hpp>

using namespace std;
using namespace edupals::cmd;

static int find_long_option(vector<Option> & options,string name)
{
    
    for (int n=0;n<options.size();n++) {
        if (options[n].name==name) {
            return n;
        }
    }
    
    return -1;
}

void ArgumentParser::add_option(Option option)
{
    options.push_back(option);
}

ParseResult ArgumentParser::parse(int argc,char* argv[])
{
    ParseResult result;
    ArgumentType eat=ArgumentType::None;
    
    for (int n=0;n<argc;n++) {
        
        string tmp = argv[n];
        
        
        // single letter
        if (tmp.size()==1) {
            result.args.push_back(tmp);
        }
        else {
            
            // short option(s)
            if (tmp[0]=='-') {
                
                //long option
                if (tmp[1]=='-') {
                    
                    //stop parsing options
                    if (tmp.size()==2) {
                        //TODO
                    }
                    else {
                        
                        //check for equal character
                        size_t equal=tmp.find('=');
                        
                        string left,right;
                        
                        if (equal!=string::npos) {
                            left=tmp.substr(2,equal-1);
                            right=tmp.substr(equal+1);
                        }
                        else {
                            left=tmp.substr(2);
                        }
                        
                        int oindex=find_long_option(options,left);
                        
                        //option not found!
                        if (oindex==-1) {
                            //TODO
                        }
                        else {
                            Option& option=options[oindex];
                            
                            if (option.type)
                        }
                    
                    }
                }
            }
            
            
        }
    }
    
    return result;
}
