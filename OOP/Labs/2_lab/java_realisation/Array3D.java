import java.util.Arrays; 

public class Array3D<T> {
	private int dim0, dim1, dim2;
	private T array[];

	public Array3D (int dim0, int dim1, int dim2) {
		this.dim0 = dim0;
		this.dim1 = dim1;
		this.dim2 = dim2;
	}

	public T[][] getValues0(Class<T> c, int i) {
		T[][] returnArr = (T[][])newInstance(Class<T> c, dim0, dim1);
		int y = 0, step = dim0 * dim1;
		for (int k = i * step; k < array.length; k += step) {
			for (int j = 0; j < dim1; j++)
				returnArr[y][j] = array[k+j];
			y++;
		}
		return returnArr;

	}

	public static void main() {
		
	}
}
