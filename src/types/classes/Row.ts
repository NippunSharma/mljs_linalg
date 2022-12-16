import { MatSize } from "./MatSize.js";
import { MatType, MatTsType } from "../primitives/Value.js";
import { Matrix } from "./Matrix.js";
import { getInstance } from "@ml.js/core";

export class Row<T extends MatTsType> extends Matrix<T> {
  constructor(matSize: MatSize, matType: MatType) {
    super({n_cols: matSize.n_cols, n_rows: 1}, matType);
  }

  init() {
    const instance: any = getInstance();

    switch (this.matType) {
      case "double":
        this.armaMat = new instance.arma_row_double();
        this.armaMat.set_size(this.matSize.n_cols);
        break;
      case "int":
        this.armaMat = new instance.arma_row_int();
        this.armaMat.set_size(this.matSize.n_cols);
        break;
      default:
        this.armaMat = new instance.arma_row_double();
        this.armaMat.set_size(this.matSize.n_cols);
    }
  }

  get(i: number): any {
    return this.armaMat.get(i);
  }

  set(i: number, val: any): boolean {
    let changed: boolean = false;
    changed = this.armaMat.set(i, val);
    return changed;
  }

  newWrapper(): Row<T> {
    const A: Row<T> = new Row<T>(this.size, this.matType);
    return A;
  }

  objType(): "mat" | "row" | "col" {
    return "row";
  }
}
