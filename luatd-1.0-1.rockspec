package = "luatd"
version = "1.0-1"
source = {
   url = "git+https://github.com/MrSyabro/luatdlib.git",
   branch = "master"
}
description = {
   summary = "Simplest TDLib JSON bind",
   homepage = "https://github.com/MrSyabro/luatdlib",
   license = "MIT/X11"
}
dependencies = {
   "lua >= 5.2"
}
build = {
   type = "builtin",
   modules = {
      luatd = {
         sources = { "luatdjson.c" },
         libraries = { "tdjson" },
      }
   }
}
