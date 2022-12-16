import { Matrix } from "../dist/classes/Matrix";
import { MatTsType } from "../dist/primitives/Value";

import { expect } from "chai";

export function ObjEqualArray<T extends MatTsType>
(
  obj: Matrix<T>,
  array: Array<T>,
  tol: number = 0
) {
  const n_rows: number = obj.size.n_rows;
  const n_cols: number = obj.size.n_cols;

  expect(n_rows * n_cols).equal(array.length,
      'JSArray and ArmaArray should have same number of elements.');

  for(var i = 0; i < n_rows; i++) {
    for(var j = 0; j < n_cols; j++) {
      expect(obj.get(i, j)).to.closeTo(array[i * n_cols + j], tol,
          `element ${obj.get(i, j)} at (${i}, ${j}) is not same as ${array[i * n_cols + j]}.`);
    }
  }
}

export function MatEqualMat<T extends MatTsType>
(
  matA: Matrix<T>,
  matB: Matrix<T>,
  tol: number = 0
) {
  expect(matA.size).eql(matB.size, 'matA and matB should have same dimensions.');

  const n_rows: number = matA.size.n_rows;
  const n_cols: number = matB.size.n_cols;

  for(var i = 0; i < n_rows; i++) {
    for(var j = 0; j < n_cols; j++) {
      expect(matA.get(i, j)).to.closeTo(matB.get(i, j), tol,
          `element at (${i}, ${j}) is not equal.`)
    }
  }
}
