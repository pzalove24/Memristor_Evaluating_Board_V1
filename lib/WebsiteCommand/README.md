Website will send a command to arduino board, then board will perform operation received

Start_<'COMMAND'>
.
.
ERROR?_<'COOMAND'>
.
.
RECEIVE_<'COMMAND'>
.
.
    //**OPTIONAL**\\
    Start_Sending_<'DATA'> 
    .
    .
    Finish_Sending_<'DATA'>
    //**OPTIONAL**\\
.
.
Finish_<'COMMAND'>

For example, you should see this in serial port interface when website send command

Start_SweepIVcurve
NO_ERROR
RECEIVE_SweepIVcurve
Start_Sending_SweepIVcurve
0.01 11.12
0.02 11.16
.
.
.
Finish_Sending_SweepIVcurve
Finish_SweepIVcurve