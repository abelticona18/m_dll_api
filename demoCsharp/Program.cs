// using System;
using System.Runtime.InteropServices;
class Program
{
    [DllImport("..\\out\\bin\\myApi.dll", CallingConvention = CallingConvention.Cdecl)]
    public static extern IntPtr CreateNumber(float val);

    [DllImport("..\\out\\bin\\myApi.dll", CallingConvention = CallingConvention.Cdecl)]
    public static extern void DestroyNumber(IntPtr p);

    [DllImport("..\\out\\bin\\myApi.dll", CallingConvention = CallingConvention.Cdecl)]
    public static extern void Print(IntPtr p);

    [DllImport("..\\out\\bin\\myApi.dll", CallingConvention = CallingConvention.Cdecl)]
    public static extern void SumTwoNumbers(IntPtr r, IntPtr n1, IntPtr n2);

    [DllImport("..\\out\\bin\\myApi.dll", CallingConvention = CallingConvention.Cdecl)]
    public static extern float Sum(float n1, float n2);

    static void Main(string[] args)
    {
        // TODO: create a wrapper to Number
        IntPtr x = CreateNumber(5);
        IntPtr y = CreateNumber(7);
        IntPtr z = CreateNumber(0);

        SumTwoNumbers(z, x, y);
        Print(z);

        float w = Sum(4, 3);
        Console.WriteLine($"[c#] Sum(float, float): {w}");

        DestroyNumber(x);
        DestroyNumber(y);
        DestroyNumber(z);
    }
}
