/*
有一副由NxN矩阵表示的图像，这里每个像素用一个int表示，请编写一个算法，在不占用额外内存空间的情况下(即不使用缓存矩阵)，将图像顺时针旋转90度。

给定一个NxN的矩阵，和矩阵的阶数N,请返回旋转后的NxN矩阵,保证N小于等于500，图像元素小于等于256。

测试样例：
[[1,2,3],[4,5,6],[7,8,9]],3
返回：[[7,4,1],[8,5,2],[9,6,3]]
*/
//运行时间： 13 ms 占用内存：756K
class Transform {
public:
    vector<vector<int> > transformImage(vector<vector<int> > mat, int n) {
        //上下交换
        for(int i = 0; i < n/2; ++i){
            for(int j = 0; j < n; ++j){
                swap(mat[i][j], mat[n-1-i][j]);
            }
        }
        //主对角线交换
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){//取i+1，对角线不需要交换
                swap(mat[i][j], mat[j][i]);
            }
        }
        return mat;
    }
};