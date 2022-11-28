import { MatSize } from "./MatSize.js";
import { MatType } from "../primitives/Value.js";
import { Matrix } from "./Matrix.js";

export class Row<T> extends Matrix<T> {
  constructor(matSize: MatSize, matType: MatType) {
    super({n_cols: matSize.n_cols, n_rows: 1}, matType);
  }

  async init() {
    const { default: instantiate } = await import("../../../resources/webml_linalg");
    const instance = await instantiate();

    switch (this.matType) {
      case "double":
        this.armaMat = new instance.arma_row_double();
        this.armaMat.set_size(this.matSize.n_cols);
        break;
      case "float":
        this.armaMat = new instance.arma_row_float();
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
}
