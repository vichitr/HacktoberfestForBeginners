#!/bin/bash
count=$(cat /root/remote-start/count.txt)
sendcount=$(("$count"+1))
echo -e "start nonce: $sendcount" > /root/remote-start/command.txt

echo "$(date +%Y-%m-%d_%H:%M:%S): Sending remote start" >> /root/remote-start/run.log

#command=$(cat /root/remote-start/command.txt)
sms=$(openssl bf -a -salt -in /root/remote-start/command.txt -kfile /root/remote-start/pass.txt)

### Insert your Device ID for Hologram here
data="{\"deviceid\": DEVIVEIDHERE, \"body\": \"PiMsg: $sms\"}"

####### Insert your Auth Code From Hologram here ###########
curl --request POST --header "Content-Type: application/json" --header "Authorization: Basic AUTHCODEHERE" --data "$dat$

echo $sendcount > /root/remote-start/count.txt

### Written by Rob Fitz
