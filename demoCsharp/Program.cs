// using System;
using System.Runtime.InteropServices;
partial class Program
{
    [DllImport("..\\out\\bin\\myApi.dll", CallingConvention = CallingConvention.Cdecl)]
    public static extern IntPtr CreateNumber(float val);

    [DllImport("..\\out\\bin\\myApi.dll", CallingConvention = CallingConvention.Cdecl)]
    public static extern void DestroyNumber(IntPtr p);

    [DllImport("..\\out\\bin\\myApi.dll", CallingConvention = CallingConvention.Cdecl)]
    public static extern void Print(IntPtr p);

    [DllImport("..\\out\\bin\\myApi.dll", CallingConvention = CallingConvention.Cdecl)]
    public static extern void SumTwoNumbers(IntPtr r, IntPtr n1, IntPtr n2);

    [LibraryImport("..\\out\\bin\\myApi.dll")]
    public static partial IntPtr GetData(IntPtr p, ref int length);

    [LibraryImport("..\\out\\bin\\myApi.dll")]
    public static partial int InitData(IntPtr p, float[] vertices, int length);

    [LibraryImport("..\\out\\bin\\myApi.dll")]
    public static partial void UpdateData(IntPtr p);

    [DllImport("..\\out\\bin\\myApi.dll", CallingConvention = CallingConvention.Cdecl)]
    public static extern float Sum(float n1, float n2);

    static void Main(string[] args)
    {
        // TODO: create a wrapper to Number
        IntPtr z = CreateNumber(0);
        int len = 0;
        float[] floatArray = [1.0f, 2.0f, 3.0f,
                                2.0f, 4.0f, 6.0f];

        InitData(z, floatArray, floatArray.Length);

        for (int i = 0; i < 10; i++)
        {
            UpdateData(z);

            IntPtr dataPtr = GetData(z, ref len);
            Marshal.Copy(dataPtr, floatArray, 0, len);

            foreach (var item in floatArray)
            {
                Console.Write($"{item}  ");
            }
            Console.WriteLine();
        }

        float w = Sum(4, 3);
        Console.WriteLine($"[c#] Sum(float, float): {w}");

        DestroyNumber(z);
    }
}
