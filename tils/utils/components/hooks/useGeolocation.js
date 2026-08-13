import { useState, useEffect } from "react";

export function useGeolocation() {
  const [coords, setCoords] = useState(null);
  useEffect(() => {
    navigator.geolocation.getCurrentPosition(
      (pos) => setCoords({ lat: pos.coords.latitude, lng: pos.coords.longitude }),
      (err) => console.error(err)
    );
  }, []);
  return coords;
}