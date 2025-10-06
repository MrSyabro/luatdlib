package = "luatd"
version = "1.0-1"
source = {
   url = "git+https://git@github.com/MrSyabro/ollama_lua.git",
   branch = "master"
}
description = {
   summary = "Simple TDLib JSON bind",
   homepage = "https://github.com/MrSyabro/ollama_lua",
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
