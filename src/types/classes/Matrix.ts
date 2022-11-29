import { MatSize } from "./MatSize.js";
import { MatType } from "../primitives/Value.js";
import { getInstance } from "../Stream.js";

export class Matrix<T> {
  // default values.
  protected armaMat: any;
  protected matSize: MatSize = { n_rows: 0, n_cols: 0 };
  protected elemType: MatType = "double";

  constructor(matSize: MatSize, matType: MatType) {
    this.elemType = matType;
    this.matSize = matSize;
  }

  async init() {
    const instance = await getInstance();
    switch (this.elemType) {
      case "double":
        this.armaMat = new instance.arma_mat_double();
        this.armaMat.set_size(this.matSize.n_rows, this.matSize.n_cols)
        break;
      case "float":
        this.armaMat = new instance.arma_mat_float();
        this.armaMat.set_size(this.matSize.n_rows, this.matSize.n_cols)
        break;
      case "int":
        this.armaMat = new instance.arma_mat_int();
        this.armaMat.set_size(this.matSize.n_rows, this.matSize.n_cols)
        break;
      default:
        this.armaMat = new instance.arma_mat_double();
        this.armaMat.set_size(this.matSize.n_rows, this.matSize.n_cols)
    }
  }

  get matType(): MatType {
    return this.elemType;
  }

  get size(): MatSize {
    return this.matSize;
  }

  get(i: number, j: number): any {
    return this.armaMat.get(i, j);
  }

  set(i: number, j: number, val: any): boolean {
    let changed: boolean = false;
    changed = this.armaMat.set(i, j, val);
    return changed;
  }

  setArmaMat(armaMat: any) {
    this.armaMat = armaMat;
  }

  getArmaMat() {
    return this.armaMat;
  }

  getSubmat(rowStart: number, colStart: number, rowEnd: number, colEnd: number): Matrix<T> {
    const submat: any = this.armaMat.get_submat(rowStart, colStart, rowEnd, colEnd);
    const submatNumRows: number = submat.n_rows();
    const submatNumCols: number = submat.n_cols();

    let submatrix: Matrix<T> = new Matrix({n_rows: submatNumRows, n_cols: submatNumCols}, this.elemType);
    submatrix.setArmaMat(submat);
    return submatrix;
  }

  fromArray(arr: Array<T>): boolean {
    const changed: boolean = this.armaMat.from_array(arr);
    return changed;
  }

  zeros() {
    this.armaMat.zeros();
  }

  ones() {
    this.armaMat.ones();
  }

  eye() {
    this.armaMat.eye();
  }

  randu() {
    this.armaMat.randu();
  }

  randn() {
    this.armaMat.randn();
  }

  fill(val: T) {
    this.armaMat.fill(val);
  }

  clean(thres: T) {
    this.armaMat.clean(thres);
  }

  replace(oldVal: T, newVal: T) {
    this.armaMat.replace(oldVal, newVal);
  }

  clamp(minVal: T, maxVal: T) {
    this.armaMat.clamp(minVal, maxVal);
  }

  transform(transformFunc: (val: T) => T) {
    this.armaMat.transform(transformFunc);
  }

  resize(newSize: MatSize) {
    this.armaMat.resize(newSize.n_rows, newSize.n_cols);
  }

  reshape(newShape: MatSize) {
    this.armaMat.reshape(newShape.n_rows, newShape.n_cols);
  }

  reset() {
    this.armaMat.reset();
  }

  toString(): String {
    return this.armaMat.str();
  }

  shedRow(rowIdx: number) {
    this.armaMat.shed_row(rowIdx);
    this.matSize.n_rows -= 1;
  }

  shedCol(colIdx: number) {
    this.armaMat.shed_col(colIdx);
    this.matSize.n_cols -= 1;
  }

  shedRows(rowStart: number, rowEnd: number) {
    this.armaMat.shed_rows(rowStart, rowEnd);
    this.matSize.n_rows -= (rowEnd - rowStart + 1);
  }

  shedCols(colStart: number, colEnd: number) {
    this.armaMat.shed_cols(colEnd, colStart);
    this.matSize.n_cols -= (colEnd - colStart + 1);
  }

  funcFill(fillFunc: any) {
    this.armaMat.func_fill(fillFunc);
  }

  t(): Matrix<T> {
    const transposed: any = this.armaMat.t();
    let transposedMatrix: Matrix<T> = new Matrix<T>({ n_rows: this.matSize.n_cols, n_cols: this.matSize.n_rows}, this.elemType);
    transposedMatrix.setArmaMat(transposed);
    return transposedMatrix;
  }

  all(condFunc: (val: T) => boolean): boolean {
    return this.armaMat.all(condFunc);
  }

  any(condFunc: (val: T) => boolean): boolean {
    return this.armaMat.any(condFunc);
  }

  newWrapper(): Matrix<T> {
    const A: Matrix<T> = new Matrix<T>(this.size, this.matType);
    return A;
  }

  objType(): "mat" | "row" | "col" {
    return "mat";
  }
}
