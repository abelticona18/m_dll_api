using System.Runtime.InteropServices;
partial class Program
{
    [DllImport("..\\out\\bin\\myApi.dll", CallingConvention = CallingConvention.Cdecl)]
    public static extern IntPtr CreateInstance(float timestep);

    [DllImport("..\\out\\bin\\myApi.dll", CallingConvention = CallingConvention.Cdecl)]
    public static extern void DestroyInstance(IntPtr p);

    [DllImport("..\\out\\bin\\myApi.dll", CallingConvention = CallingConvention.Cdecl)]
    public static extern int InitData(IntPtr p, float[] vertices, int length);

    [DllImport("..\\out\\bin\\myApi.dll", CallingConvention = CallingConvention.Cdecl)]
    public static extern IntPtr GetData(IntPtr p);

    [DllImport("..\\out\\bin\\myApi.dll", CallingConvention = CallingConvention.Cdecl)]
    public static extern void UpdateData(IntPtr p, float velocity, float period);

    static void Main(string[] args)
    {
        // TODO: create a wrapper to Number
        IntPtr instance = CreateInstance(0.01f);
        float[] floatArray = [1.0f, 2.0f, 3.0f,
                                2.0f, 4.0f, 6.0f];
        float velocity = 0.01f;
        float period = 0.1f;

        InitData(instance, floatArray, floatArray.Length);

        for (int i = 0; i < 10; i++)
        {
            UpdateData(instance, velocity, period);

            IntPtr dataPtr = GetData(instance);
            Marshal.Copy(dataPtr, floatArray, 0, floatArray.Length);

            foreach (var item in floatArray)
            {
                Console.Write($"{item}  ");
            }
            Console.WriteLine();
        }

        DestroyInstance(instance);
    }
}
