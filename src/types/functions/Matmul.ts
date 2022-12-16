import { Matrix } from "../classes/Matrix.js";
import { MatTsType } from "../primitives/Value.js";
import { getInstance } from "@ml.js/core";

export function Matmul<T extends MatTsType>(
  matA: Matrix<T>,
  matB: Matrix<T>
): Matrix<T> {
  if (matA.size.n_cols !== matB.size.n_rows) {
    throw `Size of matrices are not compatible, ${matA.size.n_cols} != ${matB.size.n_rows}.`;
  }

  const n_rows = matA.size.n_rows;
  const n_cols = matB.size.n_cols;

  const instance = getInstance();

  if ((matA.matType === "double") && (matB.matType === "double")) {
    const inner = instance.matmul_double_double((matA.asMat()).getArmaMat(), (matB.asMat()).getArmaMat());
    const result = new Matrix<T>({ n_rows, n_cols }, "double");
    result.setArmaMat(inner);
    return result;
  } else if ((matA.matType === "int") && (matB.matType === "int")) {
    const inner = instance.matmul_int_int((matA.asMat()).getArmaMat(), (matB.asMat()).getArmaMat());
    const result = new Matrix<T>({ n_rows, n_cols }, "int");
    result.setArmaMat(inner);
    return result;
  } else {
    const a = (matA.asMat()).getArmaMat();
    const b = (matB.asMat()).getArmaMat();

    const inner = instance.matmul_double_int(matA.matType === "double" ? a: b,
      matB.matType === "int" ? b: a);
    const result = new Matrix<T>({ n_rows, n_cols }, "double");
    result.setArmaMat(inner);
    return result;
  }
}
