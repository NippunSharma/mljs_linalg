import { Matrix } from "../../dist/src/types/classes/Matrix";
import { ObjEqualArray, MatEqualMat } from "../TestUtils";
import { getInstance } from "../../dist/src/types/Stream";

before("initialize", async function() {
  await getInstance();
});

describe('matrix_constructor', function() {
  it('double', function() {
    const mat: Matrix<number> = new Matrix<number>({ n_cols: 2, n_rows: 2 }, "double");
  });

  it('int', function() {
    const mat: Matrix<number> = new Matrix<number>({ n_cols: 2, n_rows: 2 }, "int");
  })
});

describe('matrix_init', function() {
  it('double', async function() {
    const mat: Matrix<number> = new Matrix<number>({ n_cols: 2, n_rows: 2 }, "double");
    await mat.init();
  });

  it('int', async function() {
    const mat: Matrix<number> = new Matrix<number>({ n_cols: 2, n_rows: 2 }, "int");
    await mat.init();
  })
});

describe('matrix_methods', function() {
  it('fromArray', async function() {
    const arr: Array<number> = [1, 2, 3, 4, 5, 6];
    const mat: Matrix<number> = new Matrix<number>({ n_cols: 3, n_rows: 2 }, "double");
    await mat.init();
    mat.fromArray(arr);
    ObjEqualArray(mat, arr);
  });

  it('zeros', async function() {
    const arr: Array<number> = new Array(25).fill(0);
    const mat: Matrix<number> = new Matrix<number>({ n_cols: 5, n_rows: 5 }, "double");
    await mat.init();
    mat.zeros();
    ObjEqualArray(mat, arr);
  });

  it('ones', async function() {
    const arr: Array<number> = new Array(25).fill(1);
    const mat: Matrix<number> = new Matrix<number>({ n_cols: 5, n_rows: 5 }, "double");
    await mat.init();
    mat.ones();
    ObjEqualArray(mat, arr);
  });

  it('eye', async function() {
    const arr: Array<number> = [1, 0, 0, 0, 0,
                                0, 1, 0, 0, 0,
                                0, 0, 1, 0, 0,
                                0, 0, 0, 1, 0,
                                0, 0, 0, 0, 1];
    const mat: Matrix<number> = new Matrix<number>({ n_cols: 5, n_rows: 5 }, "double");
    await mat.init();
    mat.eye();
    ObjEqualArray(mat, arr);
  });

  it('fill', async function() {
    const arr: Array<number> = new Array(25).fill(21);
    const mat: Matrix<number> = new Matrix<number>({ n_cols: 5, n_rows: 5 }, "double");
    await mat.init();
    mat.fill(21);
    ObjEqualArray(mat, arr);
  });

  it('funcFill', async function() {
    const arr: Array<number> = [0, 1, 2, 3, 4,
                                1, 2, 3, 4, 5,
                                2, 3, 4, 5, 6,
                                3, 4, 5, 6, 7,
                                4, 5, 6, 7, 8];
    const mat: Matrix<number> = new Matrix<number>({ n_cols: 5, n_rows: 5}, "double");
    await mat.init();
    mat.funcFill((i, j) => i + j);
    ObjEqualArray(mat, arr);
  });

  it('t', async function() {
    const arr: Array<number> = [0, 2, 3, 4, 5,
                                5, 9, 1, 2, 3,
                                1, 2, 4, 1, 9,
                                3, 2, 1, 7, 9,
                                4, 5, 1, 7, 9];

    const arrTranspose: Array<number> = [0, 5, 1, 3, 4,
                                         2, 9, 2, 2, 5,
                                         3, 1, 4, 1, 1,
                                         4, 2, 1, 7, 7,
                                         5, 3, 9, 9, 9];

    const matA: Matrix<number> = new Matrix<number>({ n_cols: 5, n_rows: 5}, "double");
    const matB: Matrix<number> = new Matrix<number>({ n_cols: 5, n_rows: 5}, "double");
    await matA.init();
    await matB.init();

    matA.fromArray(arr);
    matB.fromArray(arrTranspose);
    MatEqualMat(matA.t(), matB);
  });
});
