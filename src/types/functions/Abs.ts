import { Matrix } from "../classes/Matrix";
import { getInstance } from "@ml.js/core";
import { MatTsType } from "../primitives/Value";

export function Abs<T extends MatTsType>(A: Matrix<T>): Matrix<T> {
  let A_abs = A.newWrapper();
  const instance = getInstance();

  let inner;

  switch (A.objType()) {
    case "mat":
      switch (A.matType) {
        case "double":
          inner = instance.abs_mat_double(A.getArmaMat());
          break;
        case "int":
          inner = instance.abs_mat_int(A.getArmaMat());
          break;
      }
      break;
    case "col":
      switch (A.matType) {
        case "double":
          inner = instance.abs_col_double(A.getArmaMat());
          break;
        case "int":
          inner = instance.abs_col_int(A.getArmaMat());
          break;
      }
      break;
    case "row":
      switch (A.matType) {
        case "double":
          inner = instance.abs_row_double(A.getArmaMat());
          break;
        case "int":
          inner = instance.abs_row_int(A.getArmaMat());
          break;
      }
      break;
  }

  A_abs.setArmaMat(inner);
  return A_abs;
}
