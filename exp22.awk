BEGIN{tcp=0;udp=0;ack=0}
{
if($5=="tcp")
{
tcp++;
}
else if($5=="cbr")
udp++;
else
ack++;
}
END {printf("\ntcp=%d\nudp=%d\nack=%d\n",tcp,udp,ack);
}
