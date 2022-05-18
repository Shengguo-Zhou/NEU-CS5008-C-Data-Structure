# System Report Generation

TITLE="System Information Report for $HOSTNAME"
CURRENT_TIME=$(date +"%x %r %Z")
TIME_STAMP="Generated $CURRENT_TIME, by $USER"

report_uptime(){
  echo "
    <H2>System Uptime</H2>
    <PRE>$(uptime)</PRE>"
  return
}

report_disk_space(){
  echo "
    <H2>Disck Space</H2>
    <PRE>$(df -h)</PRE>"
  return
}

echo "<HTML>
<HEAD>
    <TITLE>$TITLE</TITLE>
</HEAD>
<BODY>
    <H1>$TITLE</H1>
    <P>$TIME_STAMP</P>
    <P>$(report_uptime)</P>
    <P>$(report_disk_space)</P>
</BODY>
</HTML>"