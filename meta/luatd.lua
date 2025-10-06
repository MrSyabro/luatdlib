---@meta
---@module 'luatd'
local luatd = {}

---@alias ClientID integer

---@return ClientID
function luatd.create_client_id()
end

---@param timeout number in second (default 10 sec)
---@return string? response json encoded response data
function luatd.receive(timeout)
end

---@param client_id ClientID
---@param request string json encoded requset data
function luatd.send(client_id, request)
end

---@param command string json encoded command data
---@return string? response json encoded response data
function luatd.execute(command)
end

return luatd