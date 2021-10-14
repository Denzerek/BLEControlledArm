#!/bin/bash


read -p 'Commit Message : ' test

#Add authentication agent
eval "$(ssh-agent -s)"

#add the path from the above .pub file to ssh 
ssh-add /c/Users/Austina/.ssh/Denzerek_key
set GIT_TRACE_PACKET=1
set GIT_TRACE=1
set GIT_CURL_VERBOSE=1

git config --global core.compression 0
git fetch --unshallow 
git pull --all