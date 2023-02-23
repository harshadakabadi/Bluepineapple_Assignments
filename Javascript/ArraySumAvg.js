function add(arr1,len)
{
    if(len==0)
    {
        return arr[0];
    }
    else
    {
        return arr1[len]+add(arr1,--len);
    }
}
let arr=[1,2,3,4,5];
let sum= add(arr,arr.length-1);
console.log("Sum is :"+sum);
console.log("Average is :"+sum/2);
