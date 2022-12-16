import { Matrix } from "../../dist/classes/Matrix";
import { ObjEqualArray, MatEqualMat } from "../TestUtils";
import { mljsInit } from "@ml.js/core";

before("initialize", async function() {
  await mljsInit();
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
  it('double', function() {
    const mat: Matrix<number> = new Matrix<number>({ n_cols: 2, n_rows: 2 }, "double");
  });

  it('int', async function() {
    const mat: Matrix<number> = new Matrix<number>({ n_cols: 2, n_rows: 2 }, "int");
  })
});

describe('matrix_methods', function() {
  it('fromArray', function() {
    const arr: Array<number> = [1, 2, 3, 4, 5, 6];
    const mat: Matrix<number> = new Matrix<number>({ n_cols: 3, n_rows: 2 }, "double");
    mat.fromArray(arr);
    ObjEqualArray(mat, arr);
  });

  it('zeros', function() {
    const arr: Array<number> = new Array(25).fill(0);
    const mat: Matrix<number> = new Matrix<number>({ n_cols: 5, n_rows: 5 }, "double");
    mat.zeros();
    ObjEqualArray(mat, arr);
  });

  it('ones', function() {
    const arr: Array<number> = new Array(25).fill(1);
    const mat: Matrix<number> = new Matrix<number>({ n_cols: 5, n_rows: 5 }, "double");
    mat.ones();
    ObjEqualArray(mat, arr);
  });

  it('eye', function() {
    const arr: Array<number> = [1, 0, 0, 0, 0,
                                0, 1, 0, 0, 0,
                                0, 0, 1, 0, 0,
                                0, 0, 0, 1, 0,
                                0, 0, 0, 0, 1];
    const mat: Matrix<number> = new Matrix<number>({ n_cols: 5, n_rows: 5 }, "double");
    mat.eye();
    ObjEqualArray(mat, arr);
  });

  it('fill', function() {
    const arr: Array<number> = new Array(25).fill(21);
    const mat: Matrix<number> = new Matrix<number>({ n_cols: 5, n_rows: 5 }, "double");
    mat.fill(21);
    ObjEqualArray(mat, arr);
  });

  it('funcFill', function() {
    const arr: Array<number> = [0, 1, 2, 3, 4,
                                1, 2, 3, 4, 5,
                                2, 3, 4, 5, 6,
                                3, 4, 5, 6, 7,
                                4, 5, 6, 7, 8];
    const mat: Matrix<number> = new Matrix<number>({ n_cols: 5, n_rows: 5}, "double");
    mat.funcFill((i, j) => i + j);
    ObjEqualArray(mat, arr);
  });

  it('t', function() {
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

    matA.fromArray(arr);
    matB.fromArray(arrTranspose);
    MatEqualMat(matA.t(), matB);
  });
});
