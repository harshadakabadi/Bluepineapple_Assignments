let actualHour=0,actualMinutes=0;
function validateTime( hour, minutes)
{
    if(hour<0 || hour>23 || minutes<0 || minutes>59)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
function actualTimeClock( hour, minutes, x)
{
    let totalValueOfX=hour*x;
    if(totalValueOfX>=60 && totalValueOfX<+120)
    {
        totalValueOfX=totalValueOfX-x;
    }
    else if(totalValueOfX>120 && totalValueOfX<=180)
    {
        totalValueOfX=totalValueOfX-2*x;
    }
    else if(totalValueOfX>180 && totalValueOfX<=240)
    {
        totalValueOfX=totalValueOfX-3*x;
    }
    else if(totalValueOfX>240 && totalValueOfX<=300)
    {
        totalValueOfX=totalValueOfX-3*x;
    }
    else if(totalValueOfX>300 && totalValueOfX<=360)
    {
        totalValueOfX=totalValueOfX-3*x;
    }
    let totalNoOfMintutes=hour*60+minutes;
    actualMinutes=totalNoOfMintutes-totalValueOfX;
    actualHour=Math.trunc(actualMinutes/60);
    actualMinutes=Math.trunc(actualMinutes%60);
}
function validateActualTimeClock(hour, minutes,x,expectedHour,expectedMinutes)
{
    actualTimeClock( hour, minutes, x);
    if((actualHour==expectedHour)&&(actualMinutes==expectedMinutes))
    {
        console.log("Successful");
    }
    else{
        console.log("Unsuccessful");
    }
}
validateActualTimeClock(7,0,10,6,0);
