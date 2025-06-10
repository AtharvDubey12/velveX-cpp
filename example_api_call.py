# example call
from api import velvet_api
import asyncio

async def get_api_response(input):
    response = await velvet_api.call_velvex(input)
    print(f"The response from the API was: {response}")

asyncio.run(get_api_response("Diff[x][x]"))
