#!/bin/bash

# Sys Report Generation

TITLE="System Information Report for $HOSTNAME"
CURRENT_TIME=$(date +"%x %r %Z")
TIME_STAMP="Generated $CURRENT_TIME, by $USER"

report_uptime(){
#     echo "uptime"
    cat << _EOF_ 
System Uptime:
$(uptime) 
_EOF_

    return
}

report_disk_space(){
# echo "disk space report generated" 
    cat << _EOF_
Disk Space
$(df)
_EOF_
    return
}

report_home_space(){
# echo "home space report generated"
    cat << _EOF_
Home Space
$(du)
_EOF_
    return
}

cat << _EOF_
TITLE: $TITLE


$TIME_STAMP 

$(report_uptime)
   